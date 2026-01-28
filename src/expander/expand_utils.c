#include "minishell.h"

int		to_expand(t_token *t)
{
	if (ft_strnstr(t->value, "$", t->len) && t->quote_type != '\'' && !t->redir_delimiter)
		return (1);
	if (!t->quote_type  && t->value && t->value[0] == '~')
		return (1);
	return (0);
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

