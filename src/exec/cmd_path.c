#include "minishell.h"

static char	*join_cmd_to_path(char *path, char *cmd_name)
{
	return (ft_strjoin3(path, "/", cmd_name));
}
char	*find_cmd_path(t_env *env, char *cmd_name)
{
	char	**all_paths;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while ( env && ft_strncmp(env->key, "PATH", 4))
		env = env->next;
	if (!env)
		return (NULL);
	all_paths = ft_split(env->value, ':');
	while (all_paths[i])
	{
		path = join_cmd_to_path(all_paths[i], cmd_name);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
