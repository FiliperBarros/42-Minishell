/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:57 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 15:27:00 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	sort_env_list(t_env *env)
{
	
} */
static int	print_export(t_env *env)
{
	if (!env)
		return (1);
	while (env)
	{
		ft_printf("declare -x ");
		ft_printf("%s", env->key);
		if (env->value)
			ft_printf("=\"%s\"", env->value);
		ft_printf("\n");
		env = env->next;
	}
	return (0);
}

static int	handle_export_arg(char *arg, t_env **env)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	get_key_and_value(*env, arg, &key, &value);
	if (!is_valid_identifier(key))
		return (print_error(" not a valid identifier\n"), 1);
	export_env(env, key, value);
	return (0);
}

static int	export_env_to_env_list(char **argv, t_env **env)
{
	int	i;
	int	return_var;

	i = 1;
	while (argv[i])
	{
		return_var = handle_export_arg(argv[i], env);
		i++;
	}
	return (return_var);
}

int	ft_export(t_cmd *cmd, t_env *env)
{
	if (!cmd->argv[1])
		return (print_export(env));
	return (export_env_to_env_list(cmd->argv, &env));
}
