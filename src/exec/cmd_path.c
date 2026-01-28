#include "minishell.h"

static char *print_cmd_not_found(char *cmd_name)
{
	print_error(cmd_name);
	print_error(": command not found\n");
	return (NULL);
}
static char	*join_cmd_to_path(char *path, char *cmd_name)
{
	return (ft_strjoin3(path, "/", cmd_name));
}
static char	*find_cmd_path(t_shell *shell, char *cmd_name)
{
	char	**all_paths;
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while ( shell->env && ft_strncmp(shell->env->key, "PATH", 4))
		shell->env = shell->env->next;
	if (!shell->env)
		return (NULL);
	all_paths = ft_split(shell->env->value, ':');
	while (all_paths[i])
	{
		path = join_cmd_to_path(all_paths[i], cmd_name);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	shell->exit_status = 127;
	return (print_cmd_not_found(cmd_name));
}

static char *validate_cmd_path(t_shell *shell, char *cmd_name)
{
    struct stat st;

    if (stat(cmd_name, &st) < 0)
    {
		shell->exit_status = 127;
        perror(cmd_name);
        return NULL;
    }
    if (S_ISDIR(st.st_mode))
    {
        print_error(cmd_name);
        print_error(": Is a directory\n");
		shell->exit_status = 126;
        return NULL;
    }
    if (access(cmd_name, X_OK) < 0)
    {
		shell->exit_status = 126;
        perror(cmd_name);
        return NULL;
    }
    return ft_strdup(cmd_name);
}

char	*solve_cmd_path(t_shell *shell, char *cmd_name)
{
	if (cmd_name && !*cmd_name)
	{
		shell->exit_status = 127;
		return (print_cmd_not_found(cmd_name));
	}
	if (ft_strrchr(cmd_name, '/'))
		return (validate_cmd_path(shell, cmd_name));
	return (find_cmd_path(shell, cmd_name));
}
