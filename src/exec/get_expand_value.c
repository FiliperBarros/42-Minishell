#include "minishell.h"

char	*get_expand_value_exec(char **dollar_pos, t_shell *shell)	
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
			|| is_quote(*after_dollar))
			value = ft_strdup("$");
		if (value && !is_quote(*after_dollar))
			(*dollar_pos)++;
	}
		return (value);
}

