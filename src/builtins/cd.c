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

void	env_set(t_env *env, char *key_to_find, char *new_value)
{
	t_env *env_node;

	env_node = get_env(env, key_to_find);
	free(env_node->value);
	env_node->value = ft_strdup(new_value); 
}
int	ft_cd(char **argv, t_env *env)
{
	char 	*path;
	char	*new_pwd;
	char	*old_pwd;

	// implementar cd ~ , cd ~/path
	if (!argv[1])
	{
		path = get_env_value(env, "HOME");
		if (!path)
			return (print_std_error("minishell: cd: HOME not set\n"), 1);
	}
	if (argv[2])
		return (print_std_error("minishell: cd: too many arguments\n"), 1);
	if (argv[1])
	{
		if (!ft_strncmp(argv[1], "-", 2))
		{
			path = get_env_value(env, "OLDPWD");
				if (!path)
					return (print_std_error("minishell: cd: OLWPWD not set\n"), 1);
		}
		else
			path = argv[1];
	}
	old_pwd = getcwd(NULL, 0);
	if (chdir(path) < 0)
		return (perror("bash : cd"), 1);
	new_pwd = getcwd(NULL, 0);
	env_set(env, "OLDPWD", old_pwd);
	env_set(env, "PWD", new_pwd);

	if (argv[1] && !ft_strncmp(argv[1], "-", 2))
		ft_printf("%s\n", new_pwd);
	return (0);
}