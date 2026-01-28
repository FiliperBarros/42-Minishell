/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:37:42 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 17:38:15 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Abre o arquivo de entrada ou retorna o fd do heredoc */
static int	open_input_redir(t_redir *redir)
{
	if (redir->type == HEREDOC)
		return (redir->heredoc_fd);
	return (open(redir->filename, O_RDONLY));
}

/* Abre o arquivo de saída conforme REDIR_OUT ou REDIR_APPEND */
static int	open_output_redir(t_redir *redir)
{
	if (redir->type == REDIR_OUT)
		return (open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	return (open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644));
}

void	apply_redirections(t_redir *redir)
{
	int	fd;
	int	target;

	while (redir)
	{
		if (redir->type == REDIR_IN || redir->type == HEREDOC)
		{
			fd = open_input_redir(redir);
			target = STDIN_FILENO;
		}
		else if (redir->type == REDIR_OUT || redir->type == REDIR_APPEND)
		{
			fd = open_output_redir(redir);
			target = STDOUT_FILENO;
		}
		if (fd < 0)
		{
			perror(redir->filename);
			exit(1);
		}
		dup2(fd, target);
		close(fd);
		redir = redir->next;
	}
}
