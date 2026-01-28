#include "minishell.h"

char	*get_expand_value_for_heredoc(char **dollar_pos, t_shell *shell)	
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
			|| is_quote(*after))
			value = ft_strdup("$");
		if (value && !is_quote(*after))
			(*dollar_pos)++;
	}
		return (value);
}
char	*expand_heredoc(t_shell *shell, char *line)
{
	char	*new_line;

	if (!ft_strchr(line, '$'))
		return (line);
	new_line = expand_word(line, ft_strlen(line), shell,'\0', 1);
	free(line);
	return (new_line);
}
