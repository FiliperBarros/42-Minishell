/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_split_expanded_tokens.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:13 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:13:14 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_without_quotes(char *line, int *i)
{
	while (line[*i] && !is_space(line[*i]))
		(*i)++;
}
static void    tokenize_expander(char *line, t_token **new_token, int *i)
{
    t_tokinfo   info;
	
    ft_bzero(&info, sizeof(t_tokinfo));
    info.token_type = WORD;
    info.start = *i;
    skip_without_quotes(line, i);
    info.end = *i;
    *new_token = create_token(line, &info);
	(*new_token)->value = ft_substr(line, info.start, info.end - info.start);
}

void	split_expanded_tokens(t_token **tokens_expanded, char *line)
{
	int	i;
	t_token *new_token;

	new_token = NULL;
	i = 0;
	while (line[i])
	{
		if(is_space(line[i]))
		{
			i++;
			continue;
		}
	tokenize_expander(line, &new_token, &i);
	add_token(tokens_expanded, new_token);
	}
}
static void	link_expanded_tokens(t_token **tk_list, t_token *exp_list, t_token *t)
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
	del_token(t, free);
}


void	check_and_split_expanded_tokens(t_token **tk_list, t_token *t)
{
	t_token *tk_list_expanded;

	tk_list_expanded = NULL;
	if (!t->quote_type && ft_strchr(t->value, ' '))
	{
		split_expanded_tokens(&tk_list_expanded, t->value);
		link_expanded_tokens(tk_list, tk_list_expanded, t);
	}
}
