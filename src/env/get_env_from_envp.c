#include "minishell.h"

static void	extract_value_key_from_envp(char *s, char **k, char **v)
{
	char *equal;

	equal = ft_strrchr(s, '=');
	*k = ft_substr(s, 0, equal - s);
	*v = ft_strdup(equal + 1);
}

static t_env	*env_new_node(char *s)
{
	t_env	*env_node;
	char 	*k;
	char	*v;
	
	k = NULL;
	v = NULL;
	env_node = malloc(sizeof(t_env));
	if (!env_node)
		return(NULL);
	extract_value_key_from_envp(s, &k, &v);
	env_node->key = k;
	env_node->value = v;
	env_node->to_hide = 0;
	env_node->next = NULL;
	return (env_node);
}

void	env_add_node(t_env **env, t_env *env_node)
{
	t_env *t;

	if (!*env)
	{
		*env = env_node;
		return ;
	}
	t = *env;
	while(t->next)
		t = t->next;
	t->next = env_node;
}

void	get_env_from_envp(t_env **env, char **envp)
{
	t_env *env_new;
	int	i;

	i = 0;
	while (envp[i])
	{
		env_new = env_new_node(envp[i]);
		env_add_node(env, env_new);
		i++;
	}
}
