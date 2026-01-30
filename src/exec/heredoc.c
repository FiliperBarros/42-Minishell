/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:01:14 by benes-al          #+#    #+#             */
/*   Updated: 2026/01/30 14:11:07 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_loop(t_shell *sh, t_redir *r, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(line, r->filename, ft_strlen(line) + 1))
		{
			free(line);
			break ;
		}
		if (!r->filename_quote)
			line = expand_heredoc(sh, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

static void	heredoc_child(t_shell *sh, t_redir *r, int fd[2])
{
	set_heredoc_signals();
	close(fd[0]);
	heredoc_loop(sh, r, fd[1]);
	close(fd[1]);
	exit(0);
}

static int	heredoc_parent(t_shell *sh, t_redir *r, int fd[2], pid_t pid)
{
	int	status;

	close(fd[1]);
	reset_signals();
	waitpid(pid, &status, 0);
	set_prompt_signals();
	if (WIFSIGNALED(status))
	{
		write(1, "\n", 1);
		close(fd[0]);
		r->heredoc_fd = -1;
		sh->exit_status = 130;
		return (0);
	}
	r->heredoc_fd = fd[0];
	return (1);
}

void	create_heredoc(t_shell *sh, t_redir *r)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		return (perror("pipe"));
	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		heredoc_child(sh, r, fd);
	heredoc_parent(sh, r, fd, pid);
}

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
			if (r->heredoc_fd == -1)
				return (0);
			r = r->next;
		}
		cmd = cmd->next;
	}
	return (1);
}
