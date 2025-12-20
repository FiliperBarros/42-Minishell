#include "minishell.h"

int		to_expand(t_token *t)
{
	return ((ft_strrchr(t->value, '$') && t->quote_type != '\'' && t->type == WORD));
}


void	check_empty_quotes(t_token *tok)
{
	char	*empty_token;

	empty_token = malloc(1);
	empty_token[0] = '\0';
	if (tok->quote_type && tok->len == 2)
	{
		tok->value = empty_token;
		tok->len = 1;
	}
}
