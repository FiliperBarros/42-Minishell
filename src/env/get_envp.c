/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al < benes-al@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:46:41 by benes-al          #+#    #+#             */
/*   Updated: 2026/01/29 15:47:02 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_envp(t_shell *sh)
{
	if (!sh->my_envp || sh->envp_dirty)
	{
		free_double_char(sh->my_envp);
		sh->my_envp = env_list_to_envp(sh->env);
		sh->envp_dirty = 0;
	}
	return (sh->my_envp);
}
