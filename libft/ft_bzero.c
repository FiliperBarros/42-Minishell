/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:59:31 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/27 16:49:57 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	(void) ft_memset(s, 0, n);
}
/*
#include <stdio.h>

int main(void)
{
	char string[10];
	ft_bzero(string,5);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",string[i]);
	}
}
*/
