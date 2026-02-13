/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* executor.c                                         :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/30 19:40:08 by frocha-b          #+#    #+#             */
/* Updated: 2026/02/13 18:30:00 by frocha-b         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "minishell.h"

static t_exec_ctx	init_exec_ctx(t_shell *sh)
{
	t_exec_ctx	ctx;

	sh->pipes_qnty = count_cmds(sh->cmd) - 1;
	sh->pipes = NULL;
	ctx.shell = sh;
	ctx.cmd = sh->cmd;
	ctx.pipes = sh->pipes;
	ctx.pipes_qnty = sh->pipes_qnty;
	ctx.current = 0;
	ctx.last_pid = -1;
	return (ctx);
}

static void	exec_cleanup(t_exec_ctx *ctx)
{
	pid_t	pid;
	int		status;

	close_all_pipes(ctx->shell->pipes, ctx->shell->pipes_qnty);
	while (1)
	{
		pid = wait(&status);
		if (pid <= 0)
			break ;
		if (pid == ctx->last_pid)
			update_exit_status(ctx->shell, status);
	}
	free_pipes(ctx->shell);
	ctx->pipes = NULL;
	set_prompt_signals();
}

static void	exec_loop_children(t_exec_ctx *ctx)
{
	t_cmd	*cmd;
	int		i;
	pid_t	pid;

	cmd = ctx->cmd;
	i = 0;
	while (cmd)
	{
		ctx->current = i;
		ignore_signals();
		pid = create_child(ctx, cmd);
		if (i == ctx->pipes_qnty)
			ctx->last_pid = pid;
		close_parent_pipes(ctx->pipes, ctx->pipes_qnty, i);
		i++;
		cmd = cmd->next;
	}
}

void	executor_loop(t_exec_ctx *ctx)
{
	if (ctx->pipes_qnty > 0)
	{
		if (!alloc_pipes(ctx->shell))
			return ;
		ctx->pipes = ctx->shell->pipes;
	}
	exec_loop_children(ctx);
	exec_cleanup(ctx);
}

void	executor(t_shell *sh)
{
	t_exec_ctx	ctx;

	if (!sh->cmd || (!sh->cmd->argv && !sh->cmd->redirs))
		return ;
	if (!prepare_all_heredocs(sh, sh->cmd))
		return ;
	if (must_execute_in_parent(sh->cmd))
		executor_parent(sh);
	else
	{
		ctx = init_exec_ctx(sh);
		executor_loop(&ctx);
	}
}
