/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:34 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:12:35 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_exit_status(t_shell *shell, int	status)
{
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if(WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}
