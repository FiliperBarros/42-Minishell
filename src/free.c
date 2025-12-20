#include "minishell.h"

void	free_tokens(t_token **tokens)
{
	t_token *t;

	while(*tokens)
	{
		t = (*tokens)->next;
		free(*tokens);
		*tokens = t;
	}
    *tokens = NULL;
}
