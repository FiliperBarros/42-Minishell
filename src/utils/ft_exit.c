/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 13:05:58 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_silent(t_shell *shell)
{
	int	final_status;

	final_status = shell->exit_status;
	free_all(shell);
	free_env(shell->env);
	exit(final_status);
}

void	ft_exit(t_shell *shell)
{
	free_all(shell);
	free_env(shell->env);
	printf("exit\n");
	exit(shell->exit_status);
}
