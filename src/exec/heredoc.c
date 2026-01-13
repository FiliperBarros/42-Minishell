#include "minishell.h"

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

	pipe(fd);

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
	r->heredoc_fd = fd[0];
}




