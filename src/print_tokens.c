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

void	print_tokens(t_token *tokens)
{
	int	i = 0;

	while (tokens)
	{
		printf("TOKEN[%d]\n", i);
		printf("  address    : %p\n", (void *)tokens);
		printf("  type       : %s\n", token_type_str(tokens->type));
		printf("  value      : %.*s\n", tokens->len, tokens->value);
		printf("  len        : %d\n", tokens->len);
		printf("  concatenate: %d\n", tokens->to_concatenate);
		printf("  quote_type : %c\n",
			tokens->quote_type ? tokens->quote_type : '-');
		printf("  next       : %p\n", (void *)tokens->next);
		printf("----------------------------\n");
		tokens = tokens->next;
		i++;
	}
}
