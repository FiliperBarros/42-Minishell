#include "minishell.h"

char	**add_arg(t_cmd *cmd, char *word)
{	
	int		i;
	int		j;
	char	**new_argv;

	i = 0;
	j = 0;
	while (cmd->argv && cmd->argv[i])
		i++;
	new_argv = malloc(sizeof(char *) * (i + 2));
	if (!new_argv)
		return (NULL);
	while (j < i)
	{
		new_argv[j] = cmd->argv[j];
		j++;
	}
	new_argv[j] = word;
	new_argv[j + 1] = NULL;
	free(cmd->argv);
	return (new_argv);
}

t_redir	*add_redir(t_cmd *curr, int redir_type, t_token *next_tk)
{
	t_redir *new_redir;
	t_redir	*head_redir;

	head_redir = curr->redirs;

	new_redir = malloc(sizeof(t_redir));
	if (!new_redir)
		return (NULL);

	new_redir->type = redir_type;
	new_redir->filename = next_tk->value;
	new_redir->filename_quote = next_tk->quote_type;
	new_redir->heredoc_fd = 0;
	new_redir->next = NULL;
	if (curr->redirs)
	{
		while (curr->redirs->next)
			curr->redirs = curr->redirs->next;
		curr->redirs->next = new_redir;
	}
	else 
		head_redir= new_redir;
	return (head_redir);
}
t_cmd *new_cmd(void)
{
	t_cmd *cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}
void	parser(t_cmd **cmd, t_token *t)
{
	t_cmd	*curr;

	*cmd = new_cmd();
	curr = *cmd;
	while (t)
	{
		if (t->type == WORD)
			curr->argv = add_arg(curr, t->value);
		else if (is_redir(t->type))
		{
			curr->redirs = add_redir(curr, t->type, t->next);
			t = t->next;
		}
		else if (t->type == PIPE)
		{
			curr->next = new_cmd();
			curr = curr->next; 
		}
		t = t->next;
	}
}
