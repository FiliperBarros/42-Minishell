/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:32:57 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:38:03 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_cmd *cmd, int pipes[][2], int pipes_qnty, int i, char **envp, char *path, t_shell *shell)
{
	setup_pipe_fds(pipes, pipes_qnty, i);
	close_all_pipes(pipes, pipes_qnty);
	if (cmd->redirs)
		apply_redirections(cmd->redirs);
	if (cmd->builtin_type)
	{
		exec_builtin_in_child(cmd, shell);
		exit(shell->exit_status);
	}
	else
	{
		execve(path, cmd->argv, envp);
		perror("execve failed!");
		exit(1);
	}
}
