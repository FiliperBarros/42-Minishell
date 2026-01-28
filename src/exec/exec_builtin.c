#include "minishell.h"

int	exec_builtin(t_cmd *cmd, t_shell *shell, int is_fork)
{
	if (cmd->builtin_type == ECHO)
		return (ft_echo(cmd->argv));
	else if (cmd->builtin_type == CD)
		return (ft_cd(cmd->argv, shell->env));
	else if (cmd->builtin_type == PWD)
		return (ft_pwd());
	else if (cmd->builtin_type == EXPORT)
		return (ft_export(cmd, shell->env));
	else if (cmd->builtin_type ==  UNSET)
		return (ft_unset(shell->env, cmd->argv));
	else if (cmd->builtin_type == ENV)
		return (ft_env(shell->env));
	else if (cmd->builtin_type == EXIT)
	{
		ft_exit_builtin(is_fork, cmd, shell);
		return (shell->exit_status);
	}
	return (1);
}
void	exec_builtin_in_child(t_cmd *cmd, t_shell *shell)
{
	if (cmd->builtin_type != EXIT)
		shell->exit_status = exec_builtin(cmd, shell, 1);
}