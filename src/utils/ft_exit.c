/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 20:38:00 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_shell *shell)
{
	free_all(shell);
	free_env(shell->env);
	free_double_char(shell->my_envp);
	printf("exit\n");
	exit(shell->exit_status);
}
