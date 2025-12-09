/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:59:56 by frocha-b          #+#    #+#             */
/*   Updated: 2025/11/25 15:17:33 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **argv)
{
	(void) ac;
	(void) argv;
	char *line;
	
	while (1)
	{
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
		if (!line)
			break;
		else
			add_history(line);
		// tokens = lexer(line);

		// tokens = expand(line);

		// if(syntax_error(tokens))
		// 	continue;

		// cmd_tree = parse(tokens);

		// exec(cmd_tree);
		
		// free_all(tokens, cmd_tree, line);
	}
		return (0);
}
