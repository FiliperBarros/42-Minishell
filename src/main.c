/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:08 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 21:54:23 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(t_shell *shell)
{
	int	status;

	while (1)
	{
		shell->line = NULL;
		shell->tokens = NULL;
		shell->cmd = NULL;
		status = handle_input(shell);
		if (status == 2)
			continue ;
		if (!parser(shell))
			continue ;
		executor(shell);
		free_all(shell);
	}
}

int	main(int ac, char **argv, char **envp)
{
	t_shell	shell;

	(void)ac;
	(void)argv;
	init_shell(&shell, envp);
	shell_loop(&shell);
	ft_exit(&shell);
	return (shell.exit_status);
}
