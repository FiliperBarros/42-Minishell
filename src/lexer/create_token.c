/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:55 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:22:11 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *line, t_tokinfo *info)
{
	t_token	*new;
	int		has_quotes;

	has_quotes = (info->quote_type != 0);
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = info->token_type;
	new->quote_type = info->quote_type;
	new->value = line + info->start + has_quotes;
	new->len = info->end - info->start - (2 * has_quotes);
	new->to_concatenate = info->to_concat;
	new->redir_delimiter = 0;
	new->next = NULL;
	return (new);
}

void	add_token(t_token **tokens, t_token *new_token)
{
	t_token	*t;

	if (!(*tokens))
	{
		(*tokens) = new_token;
		return ;
	}
	t = *tokens;
	while (t->next)
		t = t->next;
	t->next = new_token;
}
