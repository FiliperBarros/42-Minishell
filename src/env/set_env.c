#include "minishell.h"

void    set_env(t_env *env, char *key_to_find, char *new_value)
{
	t_env *env_node;

	env_node = get_env(env, key_to_find);
	if (!env_node)
		return ;
	free(env_node->value);
	env_node->value = ft_strdup(new_value); 
}
