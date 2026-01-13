#include "minishell.h"

char	*join_cmd_to_path(char *path, char *cmd_name)
{
	return (ft_strjoin3(path, "/", cmd_name));
}
char	*find_cmd_path(t_env *env, char *cmd_name)
{
	char	**all_paths;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while ( env && ft_strncmp(env->key, "PATH", 4))
		env = env->next;
	if (!env)
		return (NULL);
	all_paths = ft_split(env->value, ':');
	while (all_paths[i])
	{
		path = join_cmd_to_path(all_paths[i], cmd_name);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

void	apply_redirections(t_redir *redir)
{
	int	fd;
	int	new_fd;

	while (redir)
	{
		if (redir->type == REDIR_IN || redir->type == HEREDOC)
		{
			if (redir->type == REDIR_IN)
				fd = open(redir->filename, O_RDONLY);
			else
				fd = redir->heredoc_fd;
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

void	create_heredoc(t_redir *r)
{
	int		fd[2];
	char	*line;

	pipe(fd);

	while (1)
	{
		line = readline("> ");
		if (!line || ft_strncmp(line, r->filename, ft_strlen(line)) == 0)
		{
			free(line);
			break;
		}
	/* 	if (!r->filename_quote)
			line = expand_vars(line); */

		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	r->heredoc_fd = fd[0];
}
/* char	*expand_vars(char *line)
{
	char	*new_line;

	if (!ft_strchr(line, '$'))
		return (line);
	
} */
void	prepare_all_heredocs(t_cmd *cmd)
{
	t_redir	*r;

	while (cmd)
	{
		r = cmd->redirs;
		while (r)
		{
			if (r->type == HEREDOC)
				create_heredoc(r);
			r = r->next;
		}
		cmd = cmd->next;
	}
}
void	executor_simple(t_env *env, t_cmd *cmd)
{
	pid_t	pid;	
	char	*path;
	char	**envp;
	int		status;

	path = find_cmd_path(env, cmd->argv[0]);
	envp = env_to_envp(env);
	pid = fork();

	if (pid < 0 )
	{
		perror("fork failed");
		return ;
	}
	if (pid == 0)
	{
		prepare_all_heredocs(cmd);
		apply_redirections(cmd->redirs);
		execve(path, cmd->argv, envp);
		perror("execve failed!");e
		exit(1);
	}
	waitpid(pid, &status, 0);
	free_split(envp);
	free(path);
}
