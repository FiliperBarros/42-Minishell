#include "minishell.h"

int	update_existent_env(t_env *env, char *key, char *value, int append_flag)
{
	t_env 	*var;

	var = find_env_by_key(env, key);
	if (!var)
		return (0);
	if (value)
	{
		free(var->value);
		if (append_flag)
			var->value = value;
		else
			var->value = ft_strdup(value);
		var->to_hide = 0;
	}
	return (1);
}
void	set_env(t_env **env, char *key, char *value, int append_flag)
{
	t_env	*new_env;

	if (update_existent_env(*env, key, value, append_flag))
		return ;
	new_env = malloc(sizeof(t_env));
	new_env->key = ft_strdup(key);
	if (value)
		new_env->value = ft_strdup(value);
	else
		new_env->value = NULL;
	new_env->to_hide = (value == NULL);
	env_add_node(env, new_env);
}

void	split_key_value(char *arg, char **key, char **value, int *append_flag)
{
	char 	*equal;
	char	*append; 
	
	append 		= ft_strchr(arg, '+');
	equal		= ft_strchr(arg, '=');
	if (equal && append && append + 1== equal)
	{
		*append = '\0';
		*key = arg;
		*value = equal + 1;
		*append_flag = 1;
	}
	else if (equal)
	{
		*equal = '\0';
		*key = arg;
		*value = equal + 1;
	}
	else
	{
		*key = arg;
		*value = NULL;
	}
}

int	is_valid_identifier(char *var_name)
{
	int	i;

	i = 1;
	if (!var_name || (!ft_isalpha(var_name[0]) && var_name[0] != '_'))
		return (0);
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
