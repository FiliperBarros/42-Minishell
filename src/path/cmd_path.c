/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:30:21 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/29 15:12:00 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*print_cmd_not_found(char *cmd)
{
	print_error(cmd);
	print_error(": command not found\n");
	return (NULL);
}

static char	*join_cmd_path(char *path, char *cmd)
{
	return (ft_strjoin3(path, "/", cmd));
}

static char	*validate_cmd_path(t_shell *sh, char *cmd)
{
	struct stat	st;

	if (stat(cmd, &st) < 0)
	{
		sh->exit_status = 127;
		perror(cmd);
		return (NULL);
	}
	if (S_ISDIR(st.st_mode))
	{
		print_error(cmd);
		print_error(": Is a directory\n");
		sh->exit_status = 126;
		return (NULL);
	}
	if (access(cmd, X_OK) < 0)
	{
		sh->exit_status = 126;
		perror(cmd);
		return (NULL);
	}
	return (ft_strdup(cmd));
}

static char	*find_cmd_path(t_shell *sh, char *cmd)
{
	char	**paths;
	char	*full;
	int		i;

	i = 0;
	/* don't mutate sh->env while searching for PATH, use a local pointer */
	{
		t_env *env_ptr = sh->env;
		while (env_ptr && ft_strncmp(env_ptr->key, "PATH", 4))
			env_ptr = env_ptr->next;
		if (!env_ptr)
			return (NULL);
		paths = ft_split(env_ptr->value, ':');
	}
	while (paths[i])
	{
		full = join_cmd_path(paths[i], cmd);
		if (access(full, X_OK) == 0)
		{
			free_double_char(paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_double_char(paths);
	sh->exit_status = 127;
	return (print_cmd_not_found(cmd));
}

char	*solve_cmd_path(t_shell *sh, char *cmd)
{
	if (!cmd || !*cmd)
	{
		sh->exit_status = 127;
		return (print_cmd_not_found(cmd));
	}
	if (ft_strchr(cmd, '/'))
		return (validate_cmd_path(sh, cmd));
	return (find_cmd_path(sh, cmd));
}

int		handle_cmd_path(t_shell *shell, char *cmd_name, char **path, int pipes[][2], int pipes_qnty)
{
	*path = solve_cmd_path(shell, cmd_name);
	if (!*path)
	{
		close_all_pipes(pipes,pipes_qnty);
		return (0);
	}
	return (1);
}
