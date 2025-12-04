/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:15:28 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/11 17:38:13 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return (((char *)big) + i);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && little[j] == big[i + j])
		{
			if (little[j + 1] == 0)
				return (((char *)big) + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
