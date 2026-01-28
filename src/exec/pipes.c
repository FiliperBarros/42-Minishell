/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:33:09 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:40:58 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_pipes(int pipes[][2], int pipes_qnty)
{
	int	i;

	i = 0;
	while (i < pipes_qnty)
	{
		if (pipe(pipes[i]) == -1)
			perror("pipe");
		i++;
	}
}

void	setup_pipe_fds(int pipes[][2], int pipes_qnty, int i)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < pipes_qnty)
		dup2(pipes[i][1], STDOUT_FILENO);
}

void	close_pipe(int pipes[2])
{
	close(pipes[0]);
	close(pipes[1]);
}

void	close_parent_pipes(int pipes[][2], int pipes_qnty, int i)
{
	if (i > 0)
		close(pipes[i - 1][0]);
	if (i < pipes_qnty)
		close(pipes[i][1]);
}

void	close_all_pipes(int pipes[][2], int pipes_qnty)
{
	int	i;

	i = 0;
	while (i < pipes_qnty)
	{
		close_pipe(pipes[i]);
		i++;
	}
}
