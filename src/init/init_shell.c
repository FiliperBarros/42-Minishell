/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:07 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/02 17:55:47 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_shlvl(t_env **env)
{
	char	*shlvl;
	int		lvl;

	shlvl = get_env_value(*env, "SHLVL");
	if (!shlvl)
		set_env(*env, "SHLVL", "0");
	lvl = ft_atoi(shlvl);
	if (lvl < 0)
		lvl = 0;
	lvl++;
	set_env(*env, "SHLVL", ft_itoa(lvl));
}

void	init_shell(t_shell *shell, char **envp)
{
	ft_bzero(shell, sizeof(t_shell));
	create_env_list(&shell->env, envp);
	handle_shlvl(&shell->env);
}
