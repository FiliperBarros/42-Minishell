/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:52 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/19 11:52:57 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_shell *shell)
{
	lexer(shell, shell->line);
	if (!shell->tokens)
	{
		free_all(shell);
		if (shell->unclosed_quotes)
		{
			shell->unclosed_quotes = 0;
			print_error("minishell: syntax error: unclosed quotes\n");
		}
		return (0);
	}
	expander_and_concatenater(shell, &shell->tokens);
	if (!shell->tokens)
		return (0);
	if (validate_syntax(shell->tokens))
	{
		shell->exit_status = 2;
		free_all(shell);
		return (0);
	}
	parsing(&shell->cmd, shell->tokens);
	return (1);
}
