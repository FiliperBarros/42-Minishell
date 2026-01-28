/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:32 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 14:30:50 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "minishell.h"
/*
cd 		-> HOME 		path = $HOME  	chdir (path)
cd - 	->OLDPWD   		path = OLDPWD   chdir(path);  printf(PWD)
cd ..	->				path = PWD - SUBSTR(FT_STRRCHR('\'));

cd path	->PATH				""              ""
 

ERRORS
	HOME não existe			cd: HOME not set
	OLDPWD não existe		cd: OLDPWD not set
	Diretório não existe	cd: no such file or directory
	Não é diretório			cd: not a directory
	Permissão negada		cd: permission denied
*/

int	ft_cd(char **argv, t_env *env)
{
	char 	*path;
	char	*new_pwd;
	char	*old_pwd;
	int		argc;

	argc = count_argv_strings(argv);
	if (argc == 1)
	{
		path = get_env_value(env, "HOME");
		if (!path)
			return (print_error("minishell: cd: HOME not set\n"), 1);
	}
	if (argc == 3)
		return (print_error("minishell: cd: too many arguments\n"), 1);
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "-", 2))
		{
			path = get_env_value(env, "OLDPWD");
				if (!path)
					return (print_error("minishell: cd: OLWPWD not set\n"), 1);
		}
		else
			path = argv[1];
	}
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) < 0)
		return (perror("bash : cd"), 1);
	new_pwd = getcwd(NULL, 0);
	set_env(env, "OLDPWD", old_pwd);
	set_env(env, "PWD", new_pwd);

	if (argv[1] && !ft_strncmp(argv[1], "-", 2))
		ft_printf("%s\n", new_pwd);
	return (0);
}
