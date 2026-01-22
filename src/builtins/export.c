#include "minishell.h"

static int	print_export(t_env *env)
{
	if (!env)
		return (1);
	while (env)
	{
		printf("declare -x ");
		printf("%s", env->key);
		if (env->value)
			printf("=\"%s\"", env->value);
		printf("\n");
		env = env->next;
	}
	return (0);
}
static int	handle_export_arg(char *arg, t_env **env)
{
	char 	*key;
	char 	*value;
	int		append_flag;
	t_env 	*exist_env;

	append_flag = 0;
	split_key_value(arg, &key, &value, &append_flag);
	if (!is_valid_identifier(key))
	{
		// printf("minishell: export: `%s': not a valid identifier\n", key);
		// printf(" not a valid identifier\n");
		write (2, " not a valid identifier\n", 24);
		return (1);
	}
	if (append_flag)
	{
		exist_env = find_env_by_key(*env, key);
		if (exist_env)
			value = ft_strjoin_mod(exist_env->value, value);
	}
	set_env(env, key, value, append_flag);
	return (0);
}
static int	export_env_to_env_list(char **argv, t_env **env)
{
	int i;
	int	return_var;

	i = 1;
	while (argv[i])
	{
		return_var = handle_export_arg(argv[i], env);
		i++;
	}
	return (return_var);
}
int	ft_export(t_cmd *cmd, t_env *env)
{
	if (!cmd->argv[1])
		return (print_export(env));
	return (export_env_to_env_list(cmd->argv, &env));
}
