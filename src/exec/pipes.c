#include "minishell.h"

void	open_pipes(int	pipes[][2], int pipes_qnty)
{
	int	i;

	i = 0;
	while (i < pipes_qnty)
		pipe(pipes[i++]);
}

void	setup_pipe_fds(int pipes[][2], int pipes_qnty, int i)
{
	if (i >	0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < pipes_qnty)
		dup2(pipes[i][1], STDOUT_FILENO);
}	
void	close_pipe(int pipes[])
{
	close(pipes[0]);
	close(pipes[1]);
}

void	close_parent_pipes(int pipes[][2], int pipes_qnty, int i)
{
	if (i >	0)
		close(pipes[i - 1][0]);
	if (i < pipes_qnty)
		close(pipes[i][1]);
}

void	close_all_pipes(int pipes[][2], int pipes_qnty)
{
	int	i;

	i = 0;
	while (i < pipes_qnty)
		close_pipe(pipes[i++]);
}
