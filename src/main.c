/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:08 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/29 15:26:54 by frocha-b         ###   ########.fr       */
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
	//update my_envp when export or unset or always envp inside the loop
	//solve the apoplyy redirs case <a with no cmd and <a | >a already solves due to child returning the status
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
