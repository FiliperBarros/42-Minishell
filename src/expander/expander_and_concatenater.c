/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_and_concatenater.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:21 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 20:22:14 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(t_shell *shell, t_token **tokens)
{
	t_token	*t;

	t = *tokens;
	while (t)
	{
		if (to_expand(t))
			expand(tokens, shell, t);
		else
			t->value = ft_substr(t->value, 0, t->len);
		if (t)
			t = t->next;
	}
}

void	check_heredoc_quotes(t_token *t)
{
	if (t->redir_delimiter && !(*t->next->value))
		t->quote_type = t->next->quote_type;
	else if (t->next->redir_delimiter && !(*t->value))
		t->next->quote_type = t->quote_type;
}

void	concatenater(t_token **tokens)
{
	t_token	*t;
	t_token	*del_tk;

	t = *tokens;
	while (t)
	{
		if (t->to_concatenate)
		{
			check_heredoc_quotes(t);
			t->value = ft_strjoin(t->value, t->next->value);
			t->to_concatenate = t->next->to_concatenate;
			t->len = ft_strlen(t->value);
			del_tk = t->next;
			t->next = del_tk->next;
			del_token(del_tk, free);
		}
		else
			t = t->next;
	}
}

void	expander_and_concatenater(t_shell *shell, t_token	**tokens)
{
	expander(shell, tokens);
	concatenater(tokens);
}
