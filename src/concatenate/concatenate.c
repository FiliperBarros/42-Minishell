#include "minishell.h"

void	concatenate_tokens(t_token **tokens	)
{
	t_token *t;
	t_token *del_token;

	t = *tokens;
	while (t)
	{
		if (t->to_concatenate)
		{
			t->value = ft_strjoin(t->value, t->next->value);
			t->to_concatenate = t->next->to_concatenate;
			t->len = ft_strlen(t->value);
			del_token = t->next;
			t->next = t->next->next;
			tk_delone(del_token);
		}
		else
			t = t->next;
	}
}
