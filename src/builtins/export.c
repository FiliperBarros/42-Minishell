/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:57 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 21:56:10 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_export(t_env *env)
{
	int		len;
	t_env	**arr;

	if (!env)
		return (1);
	len = env_len(env);
	arr = malloc(sizeof(t_env *) * len);
	if (!arr)
		return (1);
	copy_env_array(arr, env);
	bubble_sort_env(arr, len);
	print_env_array(arr, len);
	free(arr);
	return (0);
}

static int	export_env_to_env_list(char **argv, t_env **env)
{
	int	i;
	int	exit_code;

	i = 1;
	while (argv[i])
	{
		exit_code = handle_export_arg(argv[i], env);
		i++;
	}
	return (exit_code);
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	if (!cmd->argv[1])
		return (print_export(env));
	return (export_env_to_env_list(cmd->argv, &env));
}
