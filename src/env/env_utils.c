/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:36:05 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/06 15:58:12 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_env(t_env *env, char *key_to_find)
{
	while (env)
	{
		if (ft_strncmp(env->key, key_to_find, ft_strlen(env->key) + 1) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

char	*get_env_value(t_env *env, char *key_to_find)
{
	t_env	*node;

	node = get_env(env, key_to_find);
	if (!node)
		return (NULL);
	return (node->value);
}

char	**env_list_to_envp(t_env *env)
{
	char	**envp;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envp = malloc(sizeof(char *) * (i + 1));
	if (!envp)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		envp[i] = ft_concat_three(tmp->key, "=", tmp->value);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

void	set_env(t_env *env, char *key_to_find, char *new_value)
{
	t_env	*node;

	node = get_env(env, key_to_find);
	if (!node)
		return ;
	free(node->value);
	node->value = new_value;
}
