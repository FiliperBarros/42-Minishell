/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:34:40 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:34:40 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**alloc_pipes(int pipes_qnty)
{
	int	**pipes;
	int	i;

	if (pipes_qnty <= 0)
		return (NULL);
	pipes = malloc(sizeof(int *) * pipes_qnty);
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < pipes_qnty)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i] || pipe(pipes[i]) < 0)
			return (free_pipes(pipes, i + 1), NULL);
		i++;
	}
	return (pipes);
}

void	free_pipes(int **pipes, int pipes_qnty)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (i < pipes_qnty)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	setup_pipe_fds(int **pipes, int pipes_qnty, int i)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < pipes_qnty)
		dup2(pipes[i][1], STDOUT_FILENO);
}

void	close_parent_pipes(int **pipes, int pipes_qnty, int i)
{
	if (i > 0)
		close(pipes[i - 1][0]);
	if (i < pipes_qnty)
		close(pipes[i][1]);
}

void	close_all_pipes(int **pipes, int pipes_qnty)
{
	int	i;

	i = 0;
	while (i < pipes_qnty)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
