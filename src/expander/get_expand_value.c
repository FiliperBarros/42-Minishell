#include "minishell.h"

static char	*get_env_value(t_env *env, char *current_pos, char **dollar_pos)
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
static char	*get_pid_value()
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
char	*get_expand_value(char **dollar_pos, t_shell *shell, t_token * t)	
{
	char	*value;
	char 	*after_dollar;
	
	value = NULL;
	after_dollar = ++(*dollar_pos);
	if (ft_isalpha(*after_dollar) || *after_dollar == '_')
		value = get_env_value(shell->env, after_dollar, dollar_pos);
	else
	{
		if (*after_dollar == '?')
			value = ft_itoa(shell->exit_status);
		else if (*after_dollar == '$')
			value = get_pid_value();
		else if (is_space(*after_dollar) || !(*after_dollar) 
			|| t->quote_type == *after_dollar)
			value = ft_strdup("$");
		if (value)
			(*dollar_pos)++;
		}
		return (value);
}







