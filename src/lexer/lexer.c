/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:00 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:28:53 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	are_quotes_closed(char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if (is_quote(line[i]))
		{
			if (quote == 0)
				quote = line[i];
			else if (quote == line[i])
				quote = 0;
		}
		i++;
	}
	return (quote == 0);
}

void	flag_all_redir_delimiters(t_token *t)
{
	while (t)
	{
		if (t->type != WORD && t->next && t->next->type == WORD)
		{
			t->next->redir_delimiter = 1;
			t = t->next;
		}
		t = t->next;
	}
	return ;
}

void	lexer(t_token **tokens, char *line)
{
	int		i;
	t_token	*new_token;

	i = 0;
	new_token = NULL;
	if (!are_quotes_closed(line))
		return ;
	while (line[i])
	{
		if (is_space(line[i]))
		{
			i++;
			continue ;
		}
		if (is_operator(line[i]))
			tokenize_operator(line, &new_token, &i);
		else
			tokenize_word(line, &new_token, &i);
		add_token(tokens, new_token);
	}
	flag_all_redir_delimiters(*tokens);
}
