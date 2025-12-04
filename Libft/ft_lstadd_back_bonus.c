/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:57:11 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/16 16:33:25 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		(*lst) = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
	
#include <stdio.h>

int	main(void)
{
	t_list	**lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*new;

	*lst = ft_lstnew((void *) "0");
	node1 = ft_lstnew((void *) "a");
	node2 = ft_lstnew((void *) "b");	
	new = ft_lstnew((void *) "c");

	while (*lst)
	{
		if (*lst->next == NULL)
			printf("%p",*lst);	
		*lst = *lst->next;
	}
	
	ft_lstadd_back(lst, new);

	while (*lst)
	{
		if (*lst->next == NULL)
			printf("%p",*lst);
			*lst = *lst->next;
	}
}
*/	
