/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:44:23 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/16 10:27:52 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*root;
	t_list	*node1;
	t_list	*new;
	
	t_list	**lst = &root;
	new = ft_lstnew((void *) "ac");
	node1 = ft_lstnew((void *) "bb");

	printf("endereco lista[0] antes%p\n", *lst);
	 printf("endereco new%p\n", new);
	ft_lstadd_front(lst, new);
	printf("endereco lista depois%p\n", *lst);
	printf("next do new%p\n\n", new->next);

	printf("endereco lista[0] antes%p\n", *lst);
	 printf("endereco node1w%p\n", node1);	
	ft_lstadd_front(lst, node1);
	printf("endereco lista depois%p\n", *lst);
	printf("next do node1%p\n", node1->next);
	

	return (0);
}*/	
