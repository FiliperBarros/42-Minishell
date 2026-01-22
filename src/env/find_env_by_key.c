#include "minishell.h"

t_env	*find_env_by_key(t_env *env, char *key_to_find)
{
	while (env)
	{
			if (ft_strncmp(env->key, key_to_find, ft_strlen(env->key) + 1) == 0)
				return (env);
			env = env->next;
	}
	return (NULL);
}