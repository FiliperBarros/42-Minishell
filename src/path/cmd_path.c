/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:12:00 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 18:12:16 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*print_cmd_not_found(t_shell *sh, char *cmd_name)
{
	sh->exit_status = 127;
	print_error(cmd_name);
	print_error(": command not found\n");
	return (NULL);
}

static char	*validate_cmd_path(t_shell *sh, char *cmd_name)
{
	struct stat	st;

	if (stat(cmd_name, &st) < 0)
	{
		sh->exit_status = 127;
		perror(cmd_name);
		return (NULL);
	}
	if (S_ISDIR(st.st_mode))
	{
		print_error(cmd_name);
		print_error(": Is a directory\n");
		sh->exit_status = 126;
		return (NULL);
	}
	if (access(cmd_name, X_OK) < 0)
	{
		sh->exit_status = 126;
		perror(cmd_name);
		return (NULL);
	}
	return (ft_strdup(cmd_name));
}

static char	*find_cmd_path(t_shell *sh, char *cmd_name)
{
	char	**paths;
	char	*full;
	int		i;

	i = 0;
	paths = ft_split(get_env_value(sh->env, "PATH"), ':');
	while (paths && paths[i])
	{
		full = ft_concat_three(paths[i], "/", cmd_name);
		if (access(full, X_OK) == 0)
		{
			free_double_char(&paths);
			return (full);
		}
		free(full);
		i++;
	}
	free_double_char(&paths);
	return (print_cmd_not_found(sh, cmd_name));
}

char	*solve_cmd_path(t_shell *sh, char *cmd_name)
{
	if (!cmd_name || !*cmd_name)
		return (print_cmd_not_found(sh, cmd_name));
	if (ft_strchr(cmd_name, '/'))
		return (validate_cmd_path(sh, cmd_name));
	return (find_cmd_path(sh, cmd_name));
}

int	handle_cmd_path(t_exec_ctx *ctx, char *cmd_name, char **path)
{
	*path = solve_cmd_path(ctx->shell, cmd_name);
	if (!*path)
	{
		close_all_pipes(ctx->pipes, ctx->pipes_qnty);
		return (0);
	}
	return (1);
}
