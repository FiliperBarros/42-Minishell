/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:10 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:13:11 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int handle_input(t_shell *shell)
{
    rl_event_hook = NULL;
    rl_on_new_line();
    set_prompt_signals();
    shell->line = readline(RL_BLUE "minishell" RL_BOLD_RED "> " ANSI_RESET);
    if (!shell->line)
    {
        ft_exit(shell); 
        return (0);
    }
    if (!(*shell->line))
        return (2); 
    add_history(shell->line);
    return (1); 
}
