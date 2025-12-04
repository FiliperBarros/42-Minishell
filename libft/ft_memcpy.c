/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:42:31 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/10 15:44:30 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
# include <stdio.h>

int	main(void)
{
	char src[10] = "abcdefghi";
	char dest[11] = "joaobaio";

	ft_memcpy(src,src +1,5);
	for (int i =0; i < 10; i++)
		printf("%c",dest[i]);
	return (0);
}*/
