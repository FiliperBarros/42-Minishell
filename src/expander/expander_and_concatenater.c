#include "minishell.h"

void	expander(t_shell *shell, t_token **tokens)
{
	t_token	*t;
	
	t = *tokens;
	while (t)
	{
		if (to_expand(t))
			expand(tokens, shell, t);
		else
			t->value = ft_substr(t->value, 0, t->len);
		if (t)
			t = t->next;
	}
}

void	concatenater(t_token **tokens)
{
	t_token *t;
	t_token *del_tk;

	t = *tokens;
	while (t)
	{
		if (t->to_concatenate)
		{
			t->value = ft_strjoin(t->value, t->next->value);
			t->to_concatenate = t->next->to_concatenate;
			t->len = ft_strlen(t->value);
			del_tk = t->next;
			t->next = del_tk->next;
			del_token(del_tk, free);
		}
		else
			t = t->next;
	}
}

void	expander_and_concatenater(t_shell *shell, t_token	**tokens)
{
	expander(shell, tokens);
	concatenater(tokens);
}
