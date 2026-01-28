/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:08 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 20:28:59 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **argv, char **envp)
{
	t_shell	shell;
	int		status;

	(void)ac;
	(void)argv;
	init_shell(&shell, envp);
	shell.my_envp = env_to_envp(shell.env);
	//update my_envp when export or unset or always envp inside the loop
	//static char *find_cmd_path(t_shell *sh, char *cmd) - free ao path**
	while (1)
	{
		shell.line = NULL;
		shell.token = NULL;
		shell.cmd = NULL;
		status = handle_input(&shell);
		if (status == 2)
			continue ;
		if (!parser(&shell))
			continue ;
		executor(&shell);
		free_all(&shell);
	}
	ft_exit(&shell);
	return (shell.exit_status);
}
