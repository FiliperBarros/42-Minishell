/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:52:24 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/15 17:50:21 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int(int n)
{
	int	count;

	count = (n < 1);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	fill_string(int n, char *str, int size)
{
	if (n > 9)
		fill_string(n / 10, str, size - 1);
	str[size] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc (sizeof(char) * (size_int(n) + 1));
	if (!str)
		return (0);
	if (n < 0)
		str[0] = '-';
	fill_string(n * ((n >= 1) - (n < 1)), str, (size_int(n) - 1));
	str[size_int(n)] = '\0';
	return (str);
}
