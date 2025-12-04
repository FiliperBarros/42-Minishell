/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:28:05 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/18 12:24:01 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_is_match(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = 0;
	end = s1_len ;
	while (ft_is_match(s1[start], set))
		start++;
	if (start >= (s1_len - 1))
		return (ft_strdup(""));
	while (ft_is_match(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

static int	ft_is_match(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s", ft_strtrim("lorem ipsum dolor sit amet", "te"));
	return (0);
}
*/
