/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:12:27 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exit(t_shell *shell)
{
    free_all(shell);
    free_env(shell->env);
    free_double_char(shell->my_envp);
    printf("exit\n");
    exit(shell->exit_status);
}
