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
void	apply_redirections(t_redir *redir)
{
	int	fd;
	int	new_fd;

	while (redir)
	{
		if (redir->type == REDIR_IN || redir->type == HEREDOC)
		{
			if (redir->type == HEREDOC)
				fd = redir->heredoc_fd;
			else
				fd = open(redir->filename, O_RDONLY);
			new_fd = STDIN_FILENO;
		}
		if (redir->type == REDIR_OUT || redir->type == REDIR_APPEND)
		{
			if (redir->type == REDIR_OUT)
				fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
			new_fd = STDOUT_FILENO;
		}
		if (fd < 0)
		{
			// print_std_error("");
			perror(redir->filename);
			exit(1);
		}
		dup2(fd, new_fd);
		close(fd);
		redir = redir->next;
	}
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
		run_cmd(cmd, pipes, pipes_qnty, i, envp, path, shell);
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
	t_cmd	*last_cmd;

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
		last_cmd = cmd;
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

void	executor(t_shell *shell, t_cmd *cmd, char **envp)
{
	if (!prepare_all_heredocs(shell, cmd))
		return ;
	if (!cmd || !cmd->argv[0])
		return ;
	if (should_run_in_parent(cmd))
	{
		executor_parent(shell, cmd);
		return ;
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	executor_loop(cmd, shell, envp);
	signal(SIGINT, sigint_prompt);
	signal(SIGQUIT, SIG_IGN);
}

