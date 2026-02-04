/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:49:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 13:52:13 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_last(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_token	*token_prev(t_token *head, t_token *target)
{
	while (head && head->next)
	{
		if (head->next == target)
			return (head);
		head = head->next;
	}
	return (NULL);
}
