/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:32 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 17:01:45 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_target_path(t_env *env, char **argv)
{
	int		argc;
	char	*path;

	argc = count_argv_strings(argv);
	if (argc == 1)
	{
		path = get_env_value(env, "HOME");
		if (!path)
			return (print_error("minishell: cd: HOME not set\n"), NULL);
	}
	if (argc == 3)
		return (print_error("minishell: cd: too many arguments\n"), NULL);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-", 2))
		{
			path = get_env_value(env, "OLDPWD");
			if (!path)
				return (print_error("minishell: cd: OLWPWD not set\n"), NULL);
		}
		else
			path = argv[1];
	}
	return (path);
}

int	ft_cd(char **argv, t_env *env)
{
	char	*path;
	char	*new_pwd;
	char	*old_pwd;

	path = get_target_path(env, argv);
	if (!path)
		return (1);
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) < 0)
		return (perror("bash : cd"), 1);
	new_pwd = getcwd(NULL, 0);
	set_env(env, "OLDPWD", old_pwd);
	set_env(env, "PWD", new_pwd);
	if (argv[1] && ft_strncmp(argv[1], "-", 2) == 0)
		ft_printf("%s\n", new_pwd);
	return (0);
}
