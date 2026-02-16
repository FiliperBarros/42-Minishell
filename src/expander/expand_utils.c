/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:17 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/16 12:15:11 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	to_expand(t_token *t)
{
	if (ft_strnstr(t->value, "$", t->len)
		&& t->quote_type != '\''
		&& !t->redir_delimiter)
		return (1);
	if (!t->quote_type && t->value && t->value[0] == '~')
		return (1);
	return (0);
}

void	append_strings(char **final_str, char *env_value)
{
	char	*new_str;

	if (!env_value)
		return ;
	new_str = ft_strjoin_mod(*final_str, env_value);
	free(*final_str);
	*final_str = new_str;
}

void	del_token(t_token *token, void (*del)(void *))
{
	if (token)
	{
		(*del)(token->value);
		free(token);
	}
}

void	del_and_link_token(t_token **token, t_token *del_t)
{
	t_token	*temp;

	if (del_t == *token)
	{
		temp = del_t->next;
		del_token(del_t, free);
		*token = temp;
	}
	else
	{
		while ((*token)->next != del_t)
			(*token) = (*token)->next;
		(*token)->next = del_t->next;
		del_token(del_t, free);
	}
}
