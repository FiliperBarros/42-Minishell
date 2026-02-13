/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:32:57 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 12:55:48 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_cleanup_exit(t_shell *sh, char *path, int status)
{
	free(path);
	sh->exit_status = status;
	ft_exit_silent(sh);
}

void	exec_child(t_exec_ctx *ctx, t_cmd *cmd, char *path)
{
	setup_pipe_fds(ctx->pipes, ctx->pipes_qnty, ctx->current);
	close_all_pipes(ctx->pipes, ctx->pipes_qnty);
	if (!apply_redirections(cmd->redirs))
		child_cleanup_exit(ctx->shell, path, 1);
	if (!cmd->argv || !cmd->argv[0])
		child_cleanup_exit(ctx->shell, path, 0);
	if (cmd->builtin_type)
	{
		ctx->shell->exit_status = exec_builtin(cmd, ctx->shell, 0);
		child_cleanup_exit(ctx->shell, path, ctx->shell->exit_status);
	}
	if (path)
	{
		execve(path, cmd->argv, env_list_to_envp(ctx->shell->env));
		perror("minishell: execve");
	}
	child_cleanup_exit(ctx->shell, path, 127);
}

pid_t	create_child(t_exec_ctx *ctx, t_cmd *cmd)
{
	pid_t	pid;
	char	*path;

	path = NULL;
	if (!cmd->builtin_type && cmd->argv && cmd->argv[0])
	{
		if (!handle_cmd_path(ctx, cmd->argv[0], &path))
			return (-1);
	}
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
