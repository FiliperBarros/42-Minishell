#include "minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token *temp;
	t_token *current;

	current = tokens;
	temp = current->next;
	while (current)
	{
		temp = current->next;
		free(current->value);
		free(current);
		current = temp;
	}
}

void	free_env(t_env *env)
{
	t_env *temp;
	t_env *current;

	current = env;
	temp = current->next;
	while (current)
	{
		temp = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = temp;
	}
}

void	free_split(char	**split_str)
{
	int	i;

	i = 0;
	if (split_str)
	{
		while (split_str[i])
		{
			free(split_str[i]);
			i++;
		}
		free(split_str);
	}
}

void	free_all(t_token *tokens, char *line)
{
	if (tokens)
		free_tokens(tokens);
	if (line)
		free(line);
}
