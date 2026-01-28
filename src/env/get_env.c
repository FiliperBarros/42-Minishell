#include "minishell.h"

char	*get_env_value(t_env *env, char *key_to_find)
{
	t_env *env_node;

	env_node = get_env(env, key_to_find);
	if (!env_node)
		return (NULL);
	return (env_node->value);
}
t_env	*get_env(t_env *env, char *key_to_find)
{
	while (env)
	{
			if (ft_strncmp(env->key, key_to_find, ft_strlen(env->key) + 1) == 0)
				return (env);
			env = env->next;
	}
	return (NULL);
}