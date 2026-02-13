/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:30:39 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 12:51:00 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_cmd *cmd, t_shell *sh, int is_parent)
{
	if (cmd->builtin_type == ECHO)
		return (ft_echo(cmd->argv));
	if (cmd->builtin_type == CD)
		return (ft_cd(cmd->argv, sh->env));
	if (cmd->builtin_type == PWD)
		return (ft_pwd());
	if (cmd->builtin_type == EXPORT)
		return (ft_export(cmd, sh->env));
	if (cmd->builtin_type == UNSET)
		return (ft_unset(sh->env, cmd->argv));
	if (cmd->builtin_type == ENV)
		return (ft_env(sh->env));
	if (cmd->builtin_type == EXIT)
	{
		ft_exit_builtin(is_parent, cmd, sh);
		return (sh->exit_status);
	}
	return (1);
}
