#include "minishell.h"


//frees missing
void	ft_exit(int	is_fork, t_cmd *cmd, t_shell *shell)
{
	shell->exit_status = 0;
	if (!is_fork)
		free_all(cmd);
	printf("exit\n");
	exit(0);
}