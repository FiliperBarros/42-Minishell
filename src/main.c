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


// char * parse_prompt(char *prompt)
// {
// 	int i;
// 	int len;

// 	len = ft_strlen(prompt);
// 	i = 0;
// 	while (prompt[i])
// 	{

// 	}
// 	return (prompt)

// }
int	main(void)
{
	char *prompt;
	// char **args;
	
	while (1)
	{
		prompt = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
		// args =  parse_prompt(prompt);
		free(prompt);
	}
		return (0);
}
