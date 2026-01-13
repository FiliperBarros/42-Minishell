#include "minishell.h"

const char *token_type_str(t_tokentype type)
{
    if (type == WORD) return "WORD";
    if (type == PIPE) return "PIPE";
    if (type == REDIR_IN) return "REDIR_IN";
    if (type == REDIR_OUT) return "REDIR_OUT";
    if (type == HEREDOC) return "HEREDOC";
    if (type == REDIR_APPEND) return "REDIR_APPEND";
    return "UNKNOWN";
}

void	print_tokens(t_token **tokens)
{
	int	i = 0;
	t_token *t;

	t = *tokens;
	while (t)
	{
		printf("TOKEN[%d]\n", i);
		printf("  address    : %p\n", (void *)t);
		printf("  type       : %s\n", token_type_str(t->type));
		printf("  redir_delim: %d\n", t->redir_delimiter);
		printf("  value      : %.*s\n", t->len, t->value);
		printf("  len        : %d\n", t->len);
		printf("  concatenate: %d\n", t->to_concatenate);
		printf("  quote_type : %c\n",
			t->quote_type ? t->quote_type : '-');
		printf("  next       : %p\n", (void *)t->next);
		printf("----------------------------\n");
		t = t->next;
		i++;
	}
	printf("\n\n\n\n\n");
}
