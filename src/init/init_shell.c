/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:07 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:13:08 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_shell(t_shell *shell, char **envp)
{
    shell->exit_status = 0;
    create_env_list(&shell->env, envp);

    // protege SHLVL=0
    /* if (!get_env(shell->env, "SHLVL"))
        add_env_var(&shell->env, "SHLVL=1"); */

}
