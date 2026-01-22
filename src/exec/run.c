#include "minishell.h"

int	run_builtin(t_cmd *cmd, t_shell *shell, int is_fork)
{
	if (cmd->builtin_type == ECHO)
		return (ft_echo(cmd->argv));
/* 	else if (cmd->builtin_type == CD)
		return (ft_cd());*/
	else if (cmd->builtin_type == PWD)
		return (ft_pwd(shell->env));
	else if (cmd->builtin_type == EXPORT)
		return (ft_export(cmd, shell->env));
	else if (cmd->builtin_type ==  UNSET)
		return (ft_unset(shell->env, cmd->argv));
	else if (cmd->builtin_type == ENV)
		return (ft_env(shell->env));
	else if (cmd->builtin_type == EXIT)
	{
		ft_exit(is_fork, cmd, shell);
		return (0);
	}
	return (1);
}

void	run_cmd(t_cmd *cmd, int pipes[][2], int pipes_qnty, int i, char **envp, char *path, t_shell *shell)
{
	setup_pipe_fds(pipes, pipes_qnty, i);
	close_all_pipes(pipes, pipes_qnty);
	if (cmd->redirs)
		apply_redirections(cmd->redirs);
	if (cmd->builtin_type)
	{
		run_builtin_in_fork(cmd, shell); 
		exit(shell->exit_status);
	}
	else
	{
		execve(path, cmd->argv, envp);
		perror("execve failed!");
		exit(1);
	}
}
void	run_builtin_in_fork(t_cmd *cmd, t_shell *shell)
{
	if (cmd->builtin_type != EXIT)
		shell->exit_status = run_builtin(cmd, shell, 1);
}

