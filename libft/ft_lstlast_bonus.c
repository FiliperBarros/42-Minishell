/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:40:43 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/16 16:26:07 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (last)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}
/*
#include <stdio.h>

int main(void)
{
    t_list  *head;
    t_list  *node1;
    t_list  *node2;

  //  head = ft_lstnew((void *)"a");
    node1 = ft_lstnew((void *)"b");
    node2 = ft_lstnew((void *)"c");

    head->next = node1;
    node1->next = node2;
    node2->next = NULL;

    printf("%p", ft_lstlast(head));
	printf("%p", node2);
    return (0);
}
*/
