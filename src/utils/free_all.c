/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:05:40 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 18:10:43 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token **tokens)
{
	t_token	*temp;
	t_token	*current;

	if (!tokens || !*tokens)
		return ;
	current = *tokens;
	while (current)
	{
		temp = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = temp;
	}
	*tokens = NULL;
}

void	free_double_char(char ***split_str)
{
	int	i;

	i = 0;
	if (!split_str || !*split_str)
		return ;
	while ((*split_str)[i])
	{
		free((*split_str)[i]);
		i++;
	}
	free(*split_str);
	*split_str = NULL;
}

void	free_redirs(t_redir **redirs)
{
	t_redir	*temp;
	t_redir	*current;

	if (!redirs || !*redirs)
		return ;
	current = *redirs;
	while (current)
	{
		temp = current->next;
		if (current->filename)
			free(current->filename);
		if (current->heredoc_fd != -1)
		{
			close(current->heredoc_fd);
			current->heredoc_fd = -1;
		}
		free(current);
		current = temp;
	}
	*redirs = NULL;
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*temp;
	t_cmd	*current;

	if (!cmd || !*cmd)
		return ;
	current = *cmd;
	while (current)
	{
		temp = current->next;
		free_double_char(&current->argv);
		free_redirs(&current->redirs);
		free(current);
		current = temp;
	}
	*cmd = NULL;
}

void	free_all(t_shell *sh)
{
	if (!sh)
		return ;
	if (sh->cmd)
		free_cmd(&sh->cmd);
	if (sh->tokens)
		free_tokens(&sh->tokens);
	if (sh->line)
	{
		free(sh->line);
		sh->line = NULL;
	}
	if (sh->pipes)
		free_pipes(sh);
}
