/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/16 15:52:40 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_newline_flag(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(char **argv)
{
	int	i;
	int	newline_flag;

	i = 1;
	if (!argv[1])
		return (0);
	newline_flag = check_newline_flag(argv[1]);
	if (newline_flag)
		i++;
	while (argv[i])
	{
		ft_printf("%s", argv[i]);
		if (argv[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!newline_flag)
		ft_printf("\n");
	return (0);
}
