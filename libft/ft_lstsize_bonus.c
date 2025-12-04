/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:29:40 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/16 16:24:23 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	head = ft_lstnew((void *)"a");
	node1 = ft_lstnew((void *) "b");
	node2 = ft_lstnew((void *) "c");
	head->next = NULL;
	node1->next = node2;
	node2-> next= NULL;
	printf("%d", ft_lstsize(head));
	return (0);
}	
*/
