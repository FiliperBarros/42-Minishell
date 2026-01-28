/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:51 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 15:26:09 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	to_append_env_value(char *append, char *equal)
{
	return (append && equal && append + 1 == equal);
}

void	export_env(t_env **env, char *new_key, char *new_value)
{
	t_env	*export_env;

	export_env = NULL;
	if (new_value)
		set_env(*env, new_key, new_value);
	else
	{
		export_env = create_env_node(new_key, new_value);
		export_env->to_hide = !new_value;
		add_env_node(env, export_env);
	}
}

void	get_key_and_value(t_env *env, char *arg, char **key, char **value)
{
	char	*equal;
	char	*append;
	t_env	*new_env;

	append = ft_strchr(arg, '+');
	equal = ft_strchr(arg, '=');
	if (equal)
	{
		*value = ft_strdup(equal + 1);
		if (to_append_env_value(append, equal))
			*append = '\0';
		else
			*equal = '\0';
	}
	*key = ft_strdup(arg);
	new_env = get_env(env, *key);
	if (new_env && to_append_env_value(append, equal))
	{
		free(*value);
		*value = ft_strjoin_mod(new_env->value, equal + 1);
	}
}

int	is_valid_identifier(char *var_name)
{
	int	i;

	i = 1;
	if (!var_name || (!ft_isalpha(var_name[0]) && var_name[0] != '_'))
		return (0);
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
