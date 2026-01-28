#include "minishell.h"

int	prepare_all_heredocs(t_shell *shell, t_cmd *cmd)
{
	t_redir	*r;

	while (cmd)
	{
		r = cmd->redirs;
		while (r)
		{
			if (r->type == HEREDOC)
				create_heredoc(shell, r);
			if(r->heredoc_fd == -1)
				return (0);
			r = r->next;
		}
		cmd = cmd->next;
	}
	return (1);
}

int		count_cmds(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}
int		handle_cmd_path(t_shell *shell, char *cmd_name, char **path, int pipes[][2], int pipes_qnty)
{
	*path = solve_cmd_path(shell, cmd_name);
	if (!*path)
	{
		close_all_pipes(pipes,pipes_qnty);
		return (0);
	}
	return (1);
}
pid_t	create_fork(t_cmd *cmd, int i, char **envp, char *path, t_shell *shell, int pipes[][2], int pipes_qnty)
{
	pid_t	pid;

	if (!cmd->builtin_type)
	{
		if (!handle_cmd_path(shell, cmd->argv[0], &path, pipes, pipes_qnty))
			return (-1);
	}
	pid = fork();
	if (pid < 0 )
		return (perror("fork failed"), -1);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_child(cmd, pipes, pipes_qnty, i, envp, path, shell);
	}
	return (pid);
}
void	executor_loop(t_cmd *cmd, t_shell *shell, char **envp)
{
	char	*path;
	int		i;	
	int		pipes[count_cmds(cmd) - 1][2];
	int		pipes_qnty;
	int		status;
	pid_t	last_pid;
	pid_t	pid;

	pipes_qnty = count_cmds(cmd) - 1;
	open_pipes(pipes, pipes_qnty);
	i = 0;
	path = NULL;
	while (cmd)
	{	
		pid = create_fork(cmd, i, envp, path, shell, pipes, pipes_qnty);
		if (i == pipes_qnty)
			last_pid = pid;
		i++;
		cmd = cmd->next;
	}
	close_all_pipes(pipes,pipes_qnty);
	while ((pid = wait(&status)) > 0)
	{
		if (pid == last_pid)
			update_exit_status(shell, status);
	}
	free(path);
}

void	executor(t_shell *sh)
{
	if (!prepare_all_heredocs(sh, sh->cmd))
		return ;
	if (!sh->cmd || !sh->cmd->argv[0])
		return ;
	if (should_run_in_parent(sh->cmd))
	{
		executor_parent(sh, sh->cmd);
		return ;
	}
	reset_signals();
	executor_loop(sh->cmd, sh, sh->my_envp);
	set_prompt_signals();
}

