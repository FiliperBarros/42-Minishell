/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:29:45 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/15 15:50:19 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == ((unsigned char)c))
		{
			ptr = (char *)s;
		}
		s++;
	}
	if (*s == ((unsigned char)c))
		ptr = (char *)s;
	return (ptr);
}
