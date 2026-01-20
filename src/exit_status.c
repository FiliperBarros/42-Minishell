#include "minishell.h"

void	update_exit_status(t_shell *shell, int	status)
{
	if (WIFEXITED(status))
		shell->exit_status = WIFEXITED(status);
	else if(WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}
