#include "minishell.h"

char	**env_to_envp(t_env *env)
{
	char	**envp;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	envp = NULL;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envp = malloc(sizeof(char *) * (i + 1));
	if (!envp)
		return (NULL);
	i = 0;
	tmp = env;
	while (tmp)
	{
		envp[i] = ft_strjoin3(tmp->key, "=", tmp->value);
		tmp = tmp->next;
		i++;
	}
	envp[i] = NULL;
	return (envp);
}