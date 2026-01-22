#include "minishell.h"

int	ft_pwd(t_env *env)
{
	t_env	*env_pwd;

	env_pwd = find_env_by_key(env, "PWD");
	ft_printf("%s\n", env_pwd->value);
	return (0);
}

