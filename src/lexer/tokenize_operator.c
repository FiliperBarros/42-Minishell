/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:03 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 19:35:14 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	detect_operator_type(t_tokinfo *info, char *line, int *i)
{
	if (line[*i] == '|')
		info->token_type = PIPE;
	else if (line[*i] == '<')
	{
		if (line[*i + 1] == '<')
		{
			info->token_type = HEREDOC;
			*i += 2;
			return ;
		}
		info->token_type = REDIR_IN;
	}
	else if (line[*i] == '>')
	{
		if (line[*i + 1] == '>')
		{
			info->token_type = REDIR_APPEND;
			*i += 2;
			return ;
		}
		info->token_type = REDIR_OUT;
	}
	(*i)++;
}

void	tokenize_operator(char *line, t_token **new_token, int *i)
{
	t_tokinfo	info;

	ft_bzero(&info, sizeof(info));
	info.start = *i;
	detect_operator_type(&info, line, i);
	info.end = *i;
	*new_token = create_token(line, &info);
}
