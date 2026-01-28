/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:42:25 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 17:42:27 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void	set_prompt_signals(void);
void	set_exec_signals(void);
void	set_heredoc_signals(void);
void	reset_signals(void);

void	sigint_prompt(int sig);
void	sigint_heredoc(int sig);

#endif
