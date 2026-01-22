#include "minishell.h"

int		should_run_in_parent(t_cmd *cmd)
{
	if (!cmd->argv && cmd->redirs)
		return (1);
	if (!cmd->next && cmd->builtin_type)
		return (1);
	return (0);
}

void	executor_parent(t_shell *shell, t_cmd *cmd)
{
	t_std_backup	backup;

	backup = backup_std_fds();
	if (cmd->redirs)
		apply_redirections(cmd->redirs);
	if (cmd->argv && cmd->builtin_type)
		shell->exit_status = run_builtin(cmd,shell, 0);
	else
		shell->exit_status = 0;
	restore_std_fds(backup);
}