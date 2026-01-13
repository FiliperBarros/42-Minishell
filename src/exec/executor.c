#include "minishell.h"

void	prepare_all_heredocs(t_shell *shell, t_cmd *cmd)
{
	t_redir	*r;

	while (cmd)
	{
		r = cmd->redirs;
		while (r)
		{
			if (r->type == HEREDOC)
				create_heredoc(shell, r);
			r = r->next;
		}
		cmd = cmd->next;
	}
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
		if (!fd)
			perror("redir_error_fd");
		dup2(fd, new_fd);
		close(fd);
		redir = redir->next;
	}
}

void	executor(t_shell *shell, t_cmd *cmd)
{
	pid_t	pid;	
	char	*path;
	char	**envp;
	int		status;

	path = NULL;
	envp = env_to_envp(shell->env);
	pid = fork();
	if (cmd->argv)
		path = find_cmd_path(shell->env, cmd->argv[0]);
	if (pid < 0 )
		return (perror("fork failed"));
	if (pid == 0)
	{
		prepare_all_heredocs(shell, cmd);
		apply_redirections(cmd->redirs);
		execve(path, cmd->argv, envp);
		// perror("execve failed!");
		exit(1);
	}
	waitpid(pid, &status, 0);
	free_double_char(envp);
	free_double_char(envp);
	free(path);
}

