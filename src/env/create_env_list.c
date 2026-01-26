#include "minishell.h"

static void	extract_value_key_from_envp(char *s, char **k, char **v)
{
	char *equal;

	equal = ft_strrchr(s, '=');
	*k = ft_substr(s, 0, equal - s);
	*v = ft_strdup(equal + 1);
}

t_env	*create_env_node(char *k, char *v)
{
	t_env	*env_node;
	
	env_node = malloc(sizeof(t_env));
	if (!env_node)
		return(NULL);
	env_node->key = k;
	env_node->value = v;
	env_node->to_hide = 0;
	env_node->next = NULL;
	return (env_node);
}
void	add_env_node(t_env **env, t_env *env_node)
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

void	create_env_list(t_env **env, char **envp)
{
	t_env 	*env_new;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (envp[i])
	{
		extract_value_key_from_envp(envp[i], &key, &value);
		env_new = create_env_node(key, value);
		add_env_node(env, env_new);
		i++;
	}
}
