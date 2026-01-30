/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:52:18 by benes-al          #+#    #+#             */
/*   Updated: 2026/01/30 15:17:15 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	create_child(t_cmd *cmd, int i, t_shell *shell, int pipes[][2], int pipes_qnty)
{
	pid_t		pid;
	char		*path;

	path = NULL;
	if (!cmd->builtin_type && !handle_cmd_path(shell, cmd->argv[0], &path, pipes, pipes_qnty))
		return (-1);
	pid = fork();
	if (pid < 0 )
		return (perror("fork failed"), -1);
	if (pid == 0)
	{
		set_exec_signals();
		exec_child(cmd, pipes, pipes_qnty, i, path, shell);
	}
	free(path);
	return (pid);
}

void	executor_loop(t_shell *shell)
{
	int		i;	
	int		pipes[count_cmds(shell->cmd) - 1][2];
	int		pipes_qnty;
	int		status;
	pid_t	last_pid;
	pid_t	pid;
	t_cmd	*cmd;

	cmd = shell->cmd;
	pipes_qnty = count_cmds(cmd) - 1;
	open_pipes(pipes, pipes_qnty);
	i = 0;
	while (cmd)
	{
		reset_signals();
		pid = create_child(cmd, i, shell, pipes, pipes_qnty);
		if (i == pipes_qnty)
			last_pid = pid;
		i++;
		cmd = cmd->next;
	}
	close_all_pipes(pipes, pipes_qnty);
	while ((pid = wait(&status)) > 0)
	{
		if (pid == last_pid)
			update_exit_status(shell, status);
	}
	set_prompt_signals();
}

void	executor(t_shell *sh)
{
	if (!sh->cmd || (!sh->cmd->argv && !sh->cmd->redirs))
		return ;
	if (!prepare_all_heredocs(sh, sh->cmd))
		return ;
	if (must_execute_in_parent(sh->cmd))
		executor_parent(sh);
	else
		executor_loop(sh);
}
