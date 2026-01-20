#include "minishell.h"

int	is_redir(int type)
{
	return (!(type == WORD || type == PIPE));
}
static int	print_syntax_error(t_token *t)
{
	if (!t)
		return (ft_printf("bash: syntax error: unexpected end of file\n"));
	if (t->type == PIPE)
		return (ft_printf("bash: syntax error near unexpected token `|'\n"));
	if (is_redir(t->type))
		return (ft_printf("bash: syntax error near unexpected token `newline'\n"));
	return (ft_printf("bash: syntax error near unexpected token `%s'\n", t->value));
}

int	validate_syntax(t_token *t)
{
	t_token *prev;

	prev = NULL;
	while (t)
	{
		if (t->type == PIPE)
		{
			if (!prev || !t->next)
				return (print_syntax_error(t));
			if( prev->type != WORD)
				return (print_syntax_error(t));
		}
		else if (is_redir(t->type))
		{
			if (!t->next || t->next->type != WORD)
				return (print_syntax_error(t));
		}
		prev = t;
		t = t->next;
	}
	return (0);
}


