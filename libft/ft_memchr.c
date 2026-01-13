/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:01:04 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/11 16:11:34 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char) c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *) (s + i));
		i++;
	}
	return (NULL);
}
