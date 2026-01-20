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
			printf("%s: No such file or directory\n", redir->filename);
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
void	exec_builtin(t_cmd *cmd)
{
	(void) cmd;
}

void	create_child(t_cmd *cmd, int i, char **envp, char *path, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		pipes[count_cmds(cmd) - 1][2];
	int		pipes_qnty;

	pipes_qnty = count_cmds(cmd) - 1;
	open_pipes(pipes, pipes_qnty);
	path = solve_cmd_path(shell->env, cmd->argv[0]);
	if (!path)
	{
		close_parent_pipes(pipes, pipes_qnty, i);
		shell->exit_status = 127;
		return ;
	}
	pid = fork();
	if (pid < 0 )
	return (perror("fork failed"));
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		run_cmd(cmd, pipes, pipes_qnty, i, envp, path, shell);
	}
	close_parent_pipes(pipes, pipes_qnty, i);
	wait(&status);
	update_exit_status(shell, status);
}
void	executor_loop(t_cmd *cmd, t_shell *shell, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (cmd)
	{	
		path = NULL;
		//check if this works
		if (cmd->builtin_type && !cmd->next)
		{
			run_builtin_in_parent(cmd, shell);
			return ;
		}
		create_child(cmd, i, envp, path, shell);
		free(path);
		i++;
		cmd = cmd->next;
	}
}

void	executor(t_shell *shell, t_cmd *cmd, char **envp)
{
	if (!prepare_all_heredocs(shell, cmd))
		return ;
	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	executor_loop(cmd, shell, envp);
	signal(SIGINT, sigint_prompt);
	signal(SIGQUIT, SIG_IGN);
}

