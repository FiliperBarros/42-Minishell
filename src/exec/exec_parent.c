/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:32:48 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 15:21:55 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	must_execute_in_parent(t_cmd *cmd)
{
	if (cmd->redirs && !cmd->argv)
		return (1);
	if (cmd->builtin_type && !cmd->next)
		return (1);
	return (0);
}

static int	exec_parent_redirs(t_cmd *cmd, t_shell *sh)
{
	if (!cmd->redirs)
		return (1);
	if (apply_redirections_parent(cmd->redirs))
		return (1);
	sh->exit_status = 1;
	return (0);
}
	

void	executor_parent(t_shell *sh)
{
	t_std_backup	backup;
	t_cmd			*cmd;

	cmd = sh->cmd;
	backup = backup_std_fds();
	if (!exec_parent_redirs(cmd, sh))
	{
		restore_std_fds(backup);
		return ;
	}
	if (cmd->argv && cmd->builtin_type)
		sh->exit_status = exec_builtin(cmd, sh, 1);
	restore_std_fds(backup);
}
