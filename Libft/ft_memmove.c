/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:53:22 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/14 14:00:28 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (num--)
		{
			((unsigned char *)dest)[num] = ((unsigned char *)src)[num];
		}
		return (dest);
	}
	ft_memcpy(dest, src, num);
	return (dest);
}
