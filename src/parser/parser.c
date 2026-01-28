/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:52 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:15:36 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_shell *shell)
{
	lexer(&shell->token, shell->line);
	if (!shell->token)
	{
		free_all(shell);
		print_error("minishell: syntax error: unclosed quotes\n");
		return (0);
	}
	expander_and_concatenater(shell, &shell->token);
	if (!shell->token)
		return (0);
	if (validate_syntax(shell->token))
	{
		shell->exit_status = 2;
		free_all(shell);
		return (0);
	}
	parsing(&shell->cmd, shell->token);
	return (1);
}
