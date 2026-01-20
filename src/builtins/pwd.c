#include "minishell.h"

int	ft_pwd(t_env *env)
{
	while (env)
	{
			if (ft_strncmp(env->key, "PWD", 4) == 0)
			{
				ft_printf("%s\n",env->value);
				return (0);
			}
			env = env->next;
	}
	return (1);
}