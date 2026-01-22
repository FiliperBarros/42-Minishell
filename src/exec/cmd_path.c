#include "minishell.h"

static char *print_cmd_not_found()
{
	// write(2, cmd_name, ft_strlen(cmd_name));
	write(2, " command not found\n", 19);
	return (NULL);
}
static char	*join_cmd_to_path(char *path, char *cmd_name)
{
	return (ft_strjoin3(path, "/", cmd_name));
}
static char	*find_cmd_path(t_env *env, char *cmd_name)
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
	return (print_cmd_not_found());
}

static char	*validate_cmd_path(char *cmd_name)
{
	if (access(cmd_name, X_OK) == 0)
		return (ft_strdup(cmd_name));
	else
	{
		ft_printf("bash: %s: No such file or directory", cmd_name);
		return (NULL);
	}
}
char	*solve_cmd_path(t_env *env, char *cmd_name)
{
	if (cmd_name && !*cmd_name)
		return (print_cmd_not_found());
	if (ft_strrchr(cmd_name, '/'))
		return (validate_cmd_path(cmd_name));
	return (find_cmd_path(env, cmd_name));
}
