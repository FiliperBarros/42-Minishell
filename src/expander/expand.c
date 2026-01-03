#include "minishell.h"


void	link_expanded_tokens(t_token **tk_list, t_token *exp_list, t_token *t)
{
	t_token *exp_list_end;
	t_token	*temp;
	
	exp_list_end = exp_list;
	while(exp_list_end->next)
		exp_list_end = exp_list_end->next;
	exp_list_end->to_concatenate = t->to_concatenate;



	if ((*tk_list)->value == t->value)
	{
		temp = *tk_list;
		(*tk_list) = exp_list;
		exp_list_end->next = temp->next;
	}
	else
	{
		while ((*tk_list)->next->value != t->value)
			(*tk_list) = (*tk_list)->next;
		(*tk_list)->next = exp_list;
		exp_list_end->next = t->next;
	}
	tk_delone(t);
}


void	check_split_tokens(t_token **tk_list, t_token *t)
{
	t_token *tk_list_expanded;

	tk_list_expanded = NULL;
	if (!t->quote_type && ft_strchr(t->value, ' '))
	{
		split_expanded_tokens(&tk_list_expanded, t->value);
		link_expanded_tokens(tk_list, tk_list_expanded, t);
	}
}

char	*get_expand_value(t_env *env, char *current_pos, char **dollar_pos)
{
	int	to_expand_len;

	to_expand_len = 0;
	while (ft_isalnum(current_pos[to_expand_len]) || current_pos[to_expand_len] == '_')
		to_expand_len++;
	*dollar_pos += to_expand_len;
	while (env)
	{
		if (ft_strncmp(current_pos, env->key, to_expand_len) == 0)
			return (env->value);
		env= env->next;
	}
	return(NULL);
}
char	*check_expand(char **dollar_pos, t_env **env)
{
	char *current_pos;

	current_pos = ++(*dollar_pos);
	// if (*current_pos == '?')
	// 		return(ft_itoa(shell->exit_status));
	if (ft_isdigit(*current_pos))
	{
		(*dollar_pos)++;
		return (NULL);
	}
	else if (*current_pos == ' ' || !(*current_pos))
		return (ft_strdup("$"));
	else
		return(get_expand_value(*env, current_pos, dollar_pos));
}

void	strjoin_modified(t_token *t, char **old_str, char *temp, char *dollar_pos)
{
	char *new_str;
	
	new_str = NULL;
	new_str = ft_strjoin(*old_str, temp);
	// if (!new_str)
	// 	free_all();
	free(*old_str);
	free(temp);
	*old_str = new_str;
	t->value = dollar_pos;
}
void	expand(t_token **tokens, t_env **env, t_token *t)
{
	char 	*dollar_pos;
	char 	*old_str;
	char	*temp;

	old_str = NULL;
	temp = NULL;
	while (*(t->value))
	{
		dollar_pos = ft_strchr(t->value, '$');
		if (!dollar_pos)
			dollar_pos = ft_strchr(t->value, '\0');
		if (t->value && t->value != dollar_pos)
			temp = ft_substr(t->value, 0, dollar_pos - t->value);
		else if (dollar_pos)
			temp = check_expand(&dollar_pos, env);
		strjoin_modified(t, &old_str, temp, dollar_pos);
	}
	t->value = old_str;
	t->len = ft_strlen(t->value);
	check_split_tokens(tokens, t);
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
		else
			not_expand(t);
		if (t->type == HEREDOC)
			flag_heredoc_delimiter(t);
		t = t->next;
	}
}

	// heredoc:
	// if (heredoc_delimiter && token->quote_type)
	// 	not_expand_inside
	// else
	// 	expand_inside;