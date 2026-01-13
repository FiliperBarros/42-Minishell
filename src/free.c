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

void	free_redirs(t_redir *redirs)
{
	t_redir *temp;

	while (redirs)
	{
		temp = redirs->next;
		free(redirs);
		redirs = temp;
	}
}
void	free_cmd(t_cmd *cmd)
{
	t_cmd	*temp;

	while (cmd)
	{
		temp = cmd->next;
		free_redirs(cmd->redirs);
		free(cmd);
		cmd = temp;
	}
}
void	free_double_char(char	**split_str)
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
