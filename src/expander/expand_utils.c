#include "minishell.h"

int		to_expand(t_token *t)
{
	return (ft_strnstr(t->value, "$", t->len) && t->quote_type != '\'' && t->type == WORD && !t->heredoc_delimiter);
}

void	flag_heredoc_delimiter(t_token *t)
{
	if (t->next->type == WORD)
		t->next->heredoc_delimiter = 1;
}
void	tk_delone(t_token *t)
{
	if (t)
	{
		free(t->value);
		free(t);
	}
}