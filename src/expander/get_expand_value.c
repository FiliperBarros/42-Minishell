/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expand_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:23 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:25:33 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_expand_value(t_env *env, char *current_pos, char **dollar_pos)
{
	size_t	to_expand_len;
	
	to_expand_len = 0;
	while (ft_isalnum(current_pos[to_expand_len]) || current_pos[to_expand_len] == '_')
		to_expand_len++;
	*dollar_pos += to_expand_len;
	while (env)
	{
		if (ft_strlen(env->key) == to_expand_len)
		{
			if (ft_strncmp(current_pos, env->key, ft_strlen(env->key)) == 0) 
				return (env->value);
		}
		env= env->next;
	}
	return (NULL);
}

char *get_tilde_expand_value(t_shell *shell, char *value)
{
    char 	*home;
	char	*expanded;
	
	home = get_env_value(shell->env, "HOME");
    if (!home)
        return (ft_strdup(value));
    expanded = ft_strjoin(home, value + 1);
    return (expanded);
}

char	*get_pid_value()
{
	int		fd;
	char	*line;
	char	*pid_value;

	fd = open("/proc/self/stat", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	pid_value = ft_substr(line, 0, ft_strchr(line, ' ') - line);
	free(line);
	return (pid_value);
}
char	*get_expand_value(char **dollar_pos, t_shell *shell, char quote_type)	
{
	char	*value;
	char 	*after;
	
	value = NULL;
	after = ++(*dollar_pos);
	if (ft_isalpha(*after) || *after == '_')
		value = get_env_expand_value(shell->env, after, dollar_pos);
	else
	{
		if (*after == '?')
			value = ft_itoa(shell->exit_status);
		else if (*after == '$')
			value = get_pid_value();
		else if (is_space(*after) || !(*after) 
			|| quote_type == *after)
			value = ft_strdup("$");
		if (value && !is_space(*after))
			(*dollar_pos)++;
	}
	return (value);
}










