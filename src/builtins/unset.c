#include "minishell.h"

static void	del_env_node(t_env *env_node, void (*del)(void *))
{
	if (env_node)
	{
		(*del)(env_node->key);
		(*del)(env_node->value);
		free(env_node);
	}
}
static void	remove_env_node(t_env **env, t_env *to_remove_node)
{
	t_env *temp;

	if (to_remove_node == *env)
	{
		temp = to_remove_node->next;
		del_env_node(to_remove_node, free);
		*env = temp;
	}
	else
	{
		while ((*env)->next != to_remove_node)
			(*env) = (*env)->next;
		(*env)->next = to_remove_node->next;
		del_env_node(to_remove_node, free);
	}
}
int	ft_unset(t_env *env, char **argv)
{
	int		i;
	t_env	*to_remove_node;

	i = 1;
	while (argv[i])
	{
		to_remove_node = get_env(env, argv[i]);
		if (to_remove_node)
			remove_env_node(&env, to_remove_node);
		i++;
	}
	return (0);
}
