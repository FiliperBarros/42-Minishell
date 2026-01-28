/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:32:48 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:37:18 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	should_run_in_parent(t_cmd *cmd)
{
	if (!cmd->argv && cmd->redirs)
		return (1);
	if (!cmd->next && cmd->builtin_type)
		return (1);
	return (0);
}

void	executor_parent(t_shell *sh, t_cmd *cmd)
{
	t_std_backup	backup;

	backup = backup_std_fds();
	if (cmd->redirs)
		apply_redirections(cmd->redirs);
	if (cmd->argv && cmd->builtin_type)
		sh->exit_status = exec_builtin(cmd, sh, 0);
	else
		sh->exit_status = 0;
	restore_std_fds(backup);
}
