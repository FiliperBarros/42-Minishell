/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:32:57 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/02 18:17:05 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_child(t_exec_ctx *ctx, t_cmd *cmd, char *path)
{
	setup_pipe_fds(ctx->pipes, ctx->pipes_qnty, ctx->current);
	close_all_pipes(ctx->pipes, ctx->pipes_qnty);
	if (!apply_redirections(cmd->redirs))
		exit(1);
	if (cmd->builtin_type)
	{
		exec_builtin_in_child(cmd, ctx->shell);
		exit(ctx->shell->exit_status);
	}
	execve(path, cmd->argv, env_list_to_envp(ctx->shell->env));
	perror("execve failed!");
	exit(1);
}

pid_t	create_child(t_exec_ctx *ctx, t_cmd *cmd)
{
	pid_t	pid;
	char	*path;

	path = NULL;
	if (!cmd->builtin_type && !handle_cmd_path(ctx, cmd->argv[0], &path))
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		return (-1);
	}
	if (pid == 0)
	{
		set_exec_signals();
		exec_child(ctx, cmd, path);
	}
	free(path);
	return (pid);
}
