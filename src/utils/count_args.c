/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:12:36 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 15:33:35 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_argv_strings(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	count_cmds(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}
