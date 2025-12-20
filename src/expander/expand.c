// #include "minishell.h"

// void	check_expand(char **dollar_pos, t_env **env, t_token *token)
// {
// 	char *current_pos;

// 	current_pos = (*dollar_pos)++;
// 	if(current_pos == '?')
// 			return(expand_exit_code(t, shell));
// 	else if (ft_isdigit(current_pos))
// 		return (remove_$_and_digit_from_token());
// 	else if(current_pos == ' ' || current_pos == '')
// 		return (literal_$);
// 	else
// 		return(tokenize_expand());
// }
// void	expand_exit_code(t_token *t, t_shell *shell)
// {
// 	t->value = ft_itoa(shell->exit_status);
// 	t->len = ft_strlen(t->value);
// }

// void	replace_all_expansions(t_env **env, t_token *t)
// {
// 	char *end_pos;
// 	char *dollar_pos;
// 	char *before_dollar_str;

// 	before_dollar_str = NULL;
// 	dollar_pos = ft_strrchr(token->value, '$');
// 	end_pos = t->value + t->len;
// 	while (dollar_pos < end_pos && dollar_pos)
// 	{
// 		if(!t->quote_type)
// 		{
// 			if (t->value != dollar_pos)
// 				before_dollar_str = ft_substr(t->value, 0, dollar_pos - t->value);
// 			check_expand(&dollar_pos, env, t);
// 		}
// 	}
// }

// void	tokenize_expand(t_token *t)
// {
// 	if(t->quote_type == '"')

// 	else
// 	{

// 	}
// }
// void	expander(t_env *env, t_token **tokens)
// {
// 	t_token	*t;

// 	t = *tokens;
// 	while (t)
// 	{
// 		if (to_expand(t))
// 			replace_all_expansions(&env, t);
// 		else if(t->quote_type)
// 			remove_quotes(t);
// 		t = t->next;
// 	}
// }

// void	remove_quotes(t_token *t)
// {
// 	t->value = (t->value)++;
// 	t->len = ft_strlen(t->value) - 2;
// }

// 	if(to_expand)
// 		if (!digit)
// 		token:
// 				char *expanded= replace_expansions;
// 				t_token **expanded= tokenize_expand(expanded);
// 				link_expanded_tokens(tokens, expanded);








