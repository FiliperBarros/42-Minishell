#include "minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token *temp;
	t_token *current;

	if (!tokens)
		return;
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
void	free_cmd(t_cmd *cmd)
{
	t_cmd	*temp;

	while (cmd)
	{
		temp = cmd->next;
		free(cmd->argv);
		free_redirs(cmd->redirs);
		free(cmd);
		cmd = temp;
	}
}

void	free_all(t_shell *sh)
{
	if (sh->cmd)
		free_cmd(sh->cmd);
	if (sh->token)
		free_tokens(sh->token);
	if (sh->line)
		free(sh->line);
}
