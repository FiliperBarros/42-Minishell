#include "minishell.h"

int	is_redir(int type)
{
	return (!(type == WORD || type == PIPE));
}
static int	print_syntax_error(t_token *t)
{
	if (!t)
		 print_error(" syntax error: unexpected end of file\n");
	else if (t->type == PIPE)
		 print_error(" syntax error near unexpected token `|'\n");
	else if (is_redir(t->type))
	{
    	if (!t->next)
        	print_error(" syntax error near unexpected token `newline'\n");
    	else
    	{
        	print_error(" syntax error near unexpected token `");
        	print_error(t->next->value);
        	print_error("'\n");
    	}
	}
	return (1);
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


