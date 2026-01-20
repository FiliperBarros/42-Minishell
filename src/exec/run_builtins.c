#include "minishell.h"

int	run_builtin(t_cmd *cmd, t_shell *shell, int is_fork)
{
	if (cmd->builtin_type == ECHO)
		return (ft_echo(cmd->argv));
/* 	else if (cmd->builtin_type == CD)
		return (ft_cd());*/
	else if (cmd->builtin_type == PWD)
		return (ft_pwd(shell->env));
/*	else if (cmd->builtin_type == EXPORT)
		return (ft_export());
	else if (cmd->builtin_type ==  UNSET)
		return (ft_unset());*/
	else if (cmd->builtin_type == ENV)
		return (ft_env(shell->env));
	else if (cmd->builtin_type == EXIT)
		ft_exit(is_fork, cmd, shell);
	return (1);
}
void	run_cmd(t_cmd *cmd, int pipes[][2], int pipes_qnty, int i, char **envp, char *path, t_shell *shell)
{
	setup_pipe_fds(pipes, pipes_qnty, i);
	close_all_pipes(pipes, pipes_qnty);
	apply_redirections(cmd->redirs);
	if (cmd->builtin_type)
		run_builtin_in_fork(cmd, shell); 
	else
	{
		execve(path, cmd->argv, envp);
		perror("execve failed!");
		exit(1);
	}
}
void	run_builtin_in_fork(t_cmd *cmd, t_shell *shell)
{
	shell->exit_status = run_builtin(cmd, shell, 1);
}


void	run_builtin_in_parent(t_cmd *cmd, t_shell *shell)
{
	t_std_backup	backup;

	backup = backup_std_fds();
	apply_redirections(cmd->redirs);
	run_builtin(cmd, shell, 0);
	restore_std_fds(backup);
}
