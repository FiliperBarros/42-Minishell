/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:07 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 15:29:46 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell, char **envp)
{
	shell->line = NULL;
	shell->token = NULL;
	shell->cmd = NULL;
	ft_bzero(shell, sizeof(t_shell));
	create_env_list(&shell->env, envp);
}
