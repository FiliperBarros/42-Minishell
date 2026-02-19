/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:26 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/19 12:43:48 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_newline_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i++] != '-' && str[i] != 'n')
		return (0);
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
	newline_flag = 0;
	if (!argv[1])
		return (ft_printf("\n"), 0);
	while (check_newline_flag(argv[i]))
	{
		newline_flag = 1;
		i++;
	}
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
