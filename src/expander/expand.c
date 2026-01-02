#include "minishell.h"

void	get_expand_value(t_env **env, char *current_pos, char **dollar_pos)
{
	int	to_expand_len;

	to_expand_len = 0;
	while (ft_isalpha(current_pos[to_expand_len] || current_pos[0] == '_'))
		to_expand_len++;
	*dollar_pos += to_expand_len;
	while(*env)
	{
		if (ft_strncmp(current_pos, (*env)->key, to_expand_len) == 0)
			return ((*env)->value);
		*env = (*env)->next;
	}
	return(NULL);
}
char	*check_expand(char **dollar_pos, t_env **env, t_token *token)
{
	char *current_pos;

	current_pos = (*dollar_pos)++;
	if (current_pos == '?')
			return(ft_itoa(shell->exit_status));
	else if (ft_isdigit(current_pos))
		return (NULL);
	else if(current_pos == ' ' || current_pos == '')
		return (ft_strdup('$'));
	else
		return(get_expand_value(env, current_pos));
}

void	strjoin_modified(t_token *t, char **old_str, char *temp, char *dollar_pos)
{
	char *new_str;

	new_str = ft_strjoin(*old_str, temp);
	free(*old_str);
	free(temp);
	*old_str = new_str;
	t->value = dollar_pos;
}

void	check_export_spaces(t_token **tokens, t_token *t)
{
	t_token **tokens_expanded;
	int		concat_flag;

	concat_flag = t->to_concatenate;
	if (!t->quote_type && ft_strrchr(t->value, ' '))
	{
		lexer_expander(tokens_expanded, t->value);
		link_expanded_tokens(tokens, *tokens_expanded, concat_flag)
	}
}

void	link_expanded_tokens(t_token **tokens, t_token *tokens_expanded, int concat_flag)
{
	t_token *next;

	while ((*tokens)->next->value != tokens_expanded->value)
		*tokens = (*tokens)->next;
	next = (*tokens)->next;
	(*tokens)->next = tokens_expanded;
	while (tokens_expanded->next)
		tokens_expanded = tokens_expanded->next;
	tokens_expanded->to_concatenate = concat_flag;
	tokens_expanded->next = next;
}

void	expand(t_token **tokens, t_env **env, t_token *t)
{
	char 	*dollar_pos;
	char 	*old_str;
	char	*temp;
	t_token **t_expanded;

	expanded = NULL;
	old_str = NULL;
	temp = NULL;
	while (t->value)
	{
		dollar_pos = ft_strrchr(token->value, '$');
		if (!dollar_pos)
			dollar_pos = ft_strrchr(t->value, '\0');
		if (t->value && t->value != dollar_pos)
			temp = ft_substr(t->value, 0, dollar_pos - t->value);
		else if (dollar_pos);
			temp = check_expand();
		strjoin_modified(t, &old_str, temp);
	}
	t->value = old_str;
	t->len = ft_strlen(t->value);
	check_export_spaces(tokens, t);
}

void	not_expand(t_token *t)
{
	if (t->quote_type)
		t->value = ft_substr(t->value, 1, t->len - 2);
	else
		t->value = ft_substr(t->value, 0, t->len);
	t->len = ft_strlen(t->value);
}
void	expander(t_env *env, t_token **tokens)
{
	t_token	*t;
	
	t = *tokens;
	while (t)
	{
		if (to_expand(t))
			expand(tokens, &env, t);
		else if 
			not_expand(t);
		if (t->type == HEREDOC)
			flag_heredoc_delimiter(t);
		t = t->next;
	}
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
		
		

		
		
		


		// int	check_expand_len(char **dollar_pos, t_env **env, t_token *token)
		// {
		// 	char *current_pos;
		
		// 	current_pos = (*dollar_pos)++;
		// 	if(current_pos == '?')
		// 			return(ft_strlen(t_shell->exit_status));
		// 	else if (ft_isdigit(current_pos))
		// 		return (0);
		// 	else if(current_pos == ' ' || current_pos == '')
		// 		return (1);
		// 	else
		// 		return(ft_strlen(t_env->value));
		// }
		// void	get_length_of_expanded_quote()
		// {
		// 	char *dollar_pos;
		
		// 	t->len = 0;
		// 	while (t->value[i] && t->value[i] != '$')
		// 		t->len++;
		// 	dollar_pos = ft_strrchr(t->value, '$');
		// 	while (dollar_pos)
		// 	{
		// 		if(!check_expand_len(dollar_pos, env, t))
		// 		{
		// 			while (t->value[i] && t->value[i] != '$')
		// 				t->len++;
		// 		}
		// 		t->len += check_expand_len(dollar_pos, env, t);
		// 		dollar_pos = ft_strrchr(t->value + i, '$');
		// 	}
		// 	while (t->value[i])
		// 				t->len++;
		// }