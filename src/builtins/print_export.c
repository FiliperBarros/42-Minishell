/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:42:17 by benes-al          #+#    #+#             */
/*   Updated: 2026/01/29 15:45:17 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(t_env *env)
{
	int	len;

	len = 0;
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}

void	copy_env_array(t_env **arr, t_env *env)
{
	int	i;

	i = 0;
	while (env)
	{
		arr[i] = env;
		i++;
		env = env->next;
	}
}

void	bubble_sort_env(t_env **arr, int len)
{
	int		i;
	int		j;
	t_env	*tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strncmp(arr[j]->key, arr[j + 1]->key,
					ft_strlen(arr[j]->key) + 1) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_env_array(t_env **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("declare -x %s", arr[i]->key);
		if (arr[i]->value)
			ft_printf("=\"%s\"", arr[i]->value);
		ft_printf("\n");
		i++;
	}
}
