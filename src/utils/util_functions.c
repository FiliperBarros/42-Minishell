/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:12 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 20:37:11 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen_mod(const	char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_mod(const char *s)
{
	char	*dup;
	int		s_len;
	int		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	dup = malloc (sizeof(char) * (s_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	char	*string;
	size_t	str_len;
	size_t	i;
	size_t	j;

	str_len = ft_strlen_mod(s1) + ft_strlen_mod(s2);
	string = malloc (sizeof (char) * (str_len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2 && s2[i])
	{
		string[j + i] = s2[i];
		i++;
	}
	string[j + i] = '\0';
	return (string);
}

char	*ft_strjoin3(char	*first_str, char *second_str, char *third_str)
{
	char	*temp;
	char	*final_str;

	temp = ft_strjoin(first_str, second_str);
	final_str = ft_strjoin(temp, third_str);
	free(temp);
	return (final_str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == ((unsigned char)c))
		{
			ptr = (char *)s;
			return (ptr);
		}
		s++;
	}
	if (*s == ((unsigned char)c))
		ptr = (char *)s;
	return (ptr);
}
