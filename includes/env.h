/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:41:44 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/29 13:29:55 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

struct s_shell;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				to_hide;
	struct s_env	*next;
}	t_env;

/* env list */
void	create_env_list(t_env **env, char **envp);
t_env	*create_env_node(char *k, char *v);
void	add_env_node(t_env **env, t_env *env_node);

/* env utils */
char	**env_list_to_envp(t_env *env);
char    **get_envp(struct s_shell *sh);
t_env	*get_env(t_env *env, char *key);
char	*get_env_value(t_env *env, char *key);
void	set_env(t_env *env, char *key, char *value);

#endif
