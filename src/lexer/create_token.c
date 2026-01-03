#include "minishell.h"

t_token *create_token(char *line, t_tokinfo *info)
{
    t_token *new_token;

    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    new_token->type = info->token_type;
    new_token->quote_type = info->quote_type;
    new_token->len = info->end - info->start;
    new_token->value = line + info->start;
    new_token->to_concatenate = info->to_concat;
    new_token->heredoc_delimiter = 0;
    new_token->next = NULL;
    return (new_token);
}

void    add_token(t_token **tokens, t_token *new_token)
{
    t_token *t;

    if (!(*tokens))
    {
        (*tokens) = new_token;
        return ;
    }
    t = *tokens;
    while (t->next)
        t = t->next;
    t->next = new_token;
}
