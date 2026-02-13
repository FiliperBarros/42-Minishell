/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:26:47 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 18:03:41 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**alloc_pipes(t_shell *shell)
{
	int	i;

	if (shell->pipes_qnty <= 0)
		return (NULL);
	shell->pipes = malloc(sizeof(int *) * shell->pipes_qnty);
	if (!shell->pipes)
		return (NULL);
	i = 0;
	while (i < shell->pipes_qnty)
	{
		shell->pipes[i] = malloc(sizeof(int) * 2);
		if (!shell->pipes[i] || pipe(shell->pipes[i]) < 0)
		{
			free_pipes(shell);
			return (NULL);
		}
		i++;
	}
	return (shell->pipes);
}

void	free_pipes(t_shell *shell)
{
	int	i;

	if (!shell || !shell->pipes)
	{
		if (shell)
			shell->pipes_qnty = 0;
		return ;
	}
	i = 0;
	while (i < shell->pipes_qnty)
	{
		if (shell->pipes[i])
			free(shell->pipes[i]);
		i++;
	}
	free(shell->pipes);
	shell->pipes = NULL;
	shell->pipes_qnty = 0;
}

void	setup_pipe_fds(int **pipes, int pipes_qnty, int i)
{
	if (!pipes)
		return ;
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < pipes_qnty)
		dup2(pipes[i][1], STDOUT_FILENO);
}

void	close_parent_pipes(int **pipes, int pipes_qnty, int i)
{
	if (!pipes)
		return ;
	if (i > 0)
		close(pipes[i - 1][0]);
	if (i < pipes_qnty)
		close(pipes[i][1]);
}

void	close_all_pipes(int **pipes, int pipes_qnty)
{
	int	i;

	if (!pipes)
		return ;
	i = 0;
	while (i < pipes_qnty)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
