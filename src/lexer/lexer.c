/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:00 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 21:07:03 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	are_quotes_unclosed(t_shell *sh, char *line)
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
	if (quote != 0)
		sh->unclosed_quotes = 1;
	return (sh->unclosed_quotes);
}

static void	flag_all_redir_delimiters(t_token *t)
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

void	lexer(t_shell *shell, char *line)
{
	int		i;
	t_token	*new_token;

	i = 0;
	new_token = NULL;
	if (are_quotes_unclosed(shell, line))
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
		add_token(&shell->tokens, new_token);
	}
	flag_all_redir_delimiters(shell->tokens);
}
