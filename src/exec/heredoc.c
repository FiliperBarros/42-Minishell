#include "minishell.h"

char	*get_expand_value_for_heredoc(char **dollar_pos, t_shell *shell)	
{
	char	*value;
	char 	*after;
	
	value = NULL;
	after = ++(*dollar_pos);
	if (ft_isalpha(*after) || *after == '_')
		value = get_env_value(shell->env, after, dollar_pos);
	else
	{
		if (*after == '?')
			value = ft_itoa(shell->exit_status);
		else if (*after == '$')
			value = get_pid_value();
		else if (is_space(*after) || !(*after) 
			|| is_quote(*after))
			value = ft_strdup("$");
		if (value && !is_quote(*after))
			(*dollar_pos)++;
	}
		return (value);
}
static char	*expand_heredoc(t_shell *shell, char *line)
{
	char	*new_line;

	if (!ft_strchr(line, '$'))
		return (line);
	new_line = expand_word(line, ft_strlen(line), shell,'\0', 1);
	free(line);
	return (new_line);
}
void	create_heredoc(t_shell *shell, t_redir *r)
{
	int		fd[2];
	char	*line;
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Create heredoc failed\n");
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(fd[0]);
		while (1)
		{
			line = readline("> ");
			if (!line || ft_strncmp(line, r->filename, ft_strlen(line)) == 0)
			{
				free(line);
				break;
			}
			if (!r->filename_quote)
				line = expand_heredoc(shell,line);
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		close(fd[1]);
	}
	signal(SIGINT, SIG_IGN);
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		// free_all(cmd);
		write(1, "\n", 1);
		close(fd[0]);
		r->heredoc_fd = -1;
		shell->exit_status = 130;
		return ;
	}
	signal(SIGINT, sigint_prompt);
	r->heredoc_fd = fd[0];
}




