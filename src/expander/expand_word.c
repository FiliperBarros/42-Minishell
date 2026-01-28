#include "minishell.h"

void	append_strings(char **final_str, char *env_value)
{
	char *new_str; 

	if (!env_value)
		return ;
	new_str = ft_strjoin_mod(*final_str, env_value);
	free(*final_str);
	*final_str = new_str;
}
 void	append_literal(char **dst, char *start, char *end)
{
	char	*part;

	if (start >= end)
		return ;
	part = ft_substr(start, 0, end - start);
	append_strings(dst, part);
}
void	append_expansion(char **final_str, char **dollar_pos, t_shell *shell, char quote_type, int exec)
{
	char	*env_value;

	if (exec)
		env_value = get_expand_value_for_heredoc(dollar_pos, shell);
	else
		env_value = get_expand_value(dollar_pos, shell, quote_type);
	append_strings(final_str, env_value);
}


char *expand_tilde(t_shell *shell, char *value)
{
    char 	*home;
	char	*expanded;
	
	home = get_env_value(shell->env, "HOME");
    if (!home)
        return (ft_strdup(value)); // ~ literal se HOME unset

    expanded = ft_strjoin(home, value + 1);
    return (expanded);
}

char	*expand_word(char *value, int len, t_shell *shell, char quote_type, int exec)
{
	char	*cursor;
	char	*final_str;
	char	*end;
	char	*next_dollar;

	cursor = value;
	if (quote_type == '\0'  && *cursor == '~')
        return (expand_tilde(shell, cursor));
	final_str = NULL;
	end = value + len;
	while (cursor < end)
	{
		next_dollar = ft_strchr(cursor, '$');
		if (!next_dollar || next_dollar > end)
			next_dollar = end;
		append_literal(&final_str, cursor, next_dollar);
		if (next_dollar < end && *next_dollar == '$')
			append_expansion(&final_str, &next_dollar, shell, quote_type, exec);
		cursor = next_dollar;
	}
	return (final_str);
}

void	expand(t_token **tokens, t_shell *shell, t_token *t)
{
	t->value = expand_word(t->value, t->len, shell, t->quote_type, 0);
	t->len = ft_strlen_mod(t->value);
	if (!t->value || (!(*t->value) && !t->quote_type))
		return (del_and_link_token(tokens, t));
	check_and_split_expanded_tokens(tokens, t);
}
