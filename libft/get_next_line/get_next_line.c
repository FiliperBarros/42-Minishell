/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:34:51 by frocha-b          #+#    #+#             */
/*   Updated: 2025/09/25 17:11:57 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_readed;

	if (fd < 0 || fd > 1024 || !BUFFER_SIZE)
		return (NULL);
	line = NULL;
	line = ft_join_buff(line, buff);
	while (!is_chr_in_str(buff, '\n'))
	{
		bytes_readed = read (fd, buff, BUFFER_SIZE);
		if (bytes_readed < 0 || buff[0] == 0)
		{
			shift_buff(buff);
			free(line);
			return (NULL);
		}
		if (!bytes_readed)
			break ;
		buff[bytes_readed] = '\0';
		line = ft_join_buff(line, buff);
	}
	shift_buff(buff);
	return (line);
}
/* 
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	char	*str;
	while ((str = get_next_line(fd)))
	{
		printf ("%s",str);
		free(str);
	}
	return (0);
} */