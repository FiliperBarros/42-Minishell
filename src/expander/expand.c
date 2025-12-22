#include "minishell.h"

void	check_expand(char **dollar_pos, t_env **env, t_token *token)
{
	char *current_pos;

	current_pos = (*dollar_pos)++;
	if(current_pos == '?')
			return(expand_exit_code(t, shell));
	else if (ft_isdigit(current_pos))
		return (remove_$_and_digit_from_token());
	else if(current_pos == ' ' || current_pos == '')
		return (literal_$);
	else
		return(tokenize_expand());
}

int	check_expand_len(char **dollar_pos, t_env **env, t_token *token)
{
	char *current_pos;

	current_pos = (*dollar_pos)++;
	if(current_pos == '?')
			return(ft_strlen(t_shell->exit_status));
	else if (ft_isdigit(current_pos))
		return (0);
	else if(current_pos == ' ' || current_pos == '')
		return (1);
	else
		return(ft_strlen(t_env->value));
}


void	expand_with_quotes()
{
	while (dollar_pos < end_pos && dollar_pos)
	{
			if (t->value != dollar_pos)
				before_dollar_str = ft_substr(t->value, 0, dollar_pos - t->value);
			check_expand(&dollar_pos, env, t);
	}
	t->len++;
}

void	get_length_of_expanded_quote()
{
	char *dollar_pos;

	t->len = 0;
	while (t->value[i] && t->value[i] != '$')
		t->len++;
	dollar_pos = ft_strrchr(t->value, '$');
	while (dollar_pos)
	{
		if(!check_expand_len(dollar_pos, env, t))
		{
			while (t->value[i] && t->value[i] != '$')
				t->len++;
		}
		t->len += check_expand_len(dollar_pos, env, t);
		dollar_pos = ft_strrchr(t->value + i, '$');
	}
	while (t->value[i])
				t->len++;
}

void	expand_without_quotes(t_env **env, t_token *t)
{
}
void	replace_all_expansions(t_env **env, t_token *t)
{
	char *end_pos;
	char *dollar_pos;

	dollar_pos = ft_strrchr(token->value, '$');
	end_pos = t->value + t->len;
	if (t->quote_type)
		expand_with_quotes();
	else
		expand_without_quotes();
}


void	expander(t_env *env, t_token **tokens)
{
	t_token	*t;
	
	t = *tokens;
	while (t)
	{
		if (t->type == HEREDOC)
			reflag_heredoc_delimiter(t);
		else if (to_expand(t))
			replace_all_expansions(&env, t);
		else if (t->quote_type)
			remove_quotes(t);
		t = t->next;
	}
}

void	tokenize_expand(t_token *t)
{
}
	if(to_expand)
		if (!digit)
		token:
				char *expanded= replace_expansions;
				t_token **expanded= tokenize_expand(expanded);
				link_expanded_tokens(tokens, expanded);

heredoc:
if (heredoc_delimiter && token->quote_type)
	not_expand_inside
else
	expand_inside;








