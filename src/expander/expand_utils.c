#include "minishell.h"


int		to_expand(t_token *t)
{
	return (ft_strnstr(t->value, "$", t->len) && t->quote_type != '\'' && !t->redir_delimiter);
}

void	del_token(t_token *token, void (*del)(void *))
{
	if (token)
	{
		(*del)(token->value);
		free(token);
	}
}

void	del_and_link_token(t_token **token, t_token *del_t)
{
	t_token *temp;

	if (del_t == *token)
	{
		temp = del_t->next;
		del_token(del_t, free);
		*token = temp;
	}
	else
	{
		while ((*token)->next != del_t)
			(*token) = (*token)->next;
		(*token)->next = del_t->next;
		del_token(del_t, free);
	}
}

/* void	del_and_link_token(t_token **head, t_token *entry)
{
	t_token **indirect;

	indirect = head;
	while (*indirect != entry)
		indirect = &((*indirect)->next);
	*indirect = entry->next;
	del_token(entry, free);
} */
