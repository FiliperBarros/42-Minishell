/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:34:21 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/16 16:22:39 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = malloc (sizeof(t_list));
	if (!root)
		return (NULL);
	root->content = content;
	root->next = NULL;
	return (root);
}

/*#include <stdio.h>

int	main(void)
{
	t_list	*test;
	t_list	*test2;
	char	*c = "A";
	char	*c2 = "B";
	test = ft_lstnew((void *)c);
	test2 = ft_lstnew((void *)c2);
	printf( "%s\n",(char*)test->content);
	printf("Antes: %p\n", test->next);
	test->next = test2;
	printf("Depois: %p\n", test->next);
	printf( "%s\n",(char*)test2->content);
	printf("%p\n", test2->next);
	
	return (0);
}
*/
