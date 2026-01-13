/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:56:19 by frocha-b          #+#    #+#             */
/*   Updated: 2025/09/25 17:13:28 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_len(char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
		i++;
	while (buff && buff[j] && buff[j] != '\n')
		j++;
	if (buff[j] == '\n')
		j++;
	return (i + j);
}

char	*ft_join_buff(char *line, char *buff)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = malloc ((ft_line_len(line, buff)) + 1);
	if (!new_line)
		return (free(line), NULL);
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while (i + j < ft_line_len(line, buff))
	{
		new_line[i + j] = buff[j];
		j++;
	}
	new_line[i + j] = '\0';
	free(line);
	if (!new_line)
		return (free(new_line), NULL);
	return (new_line);
}

int	is_chr_in_str(char *buffer, char c)
{
	while (*buffer)
	{
		if (*buffer == c)
			return (1);
		buffer++;
	}
	return (0);
}

void	shift_buff(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}
