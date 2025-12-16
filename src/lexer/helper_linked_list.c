#include "minishell.h"

t_token *create_token(char *line, t_tokentype type, t_tokinfo token_info)
{
    t_token *new_token;

    new_token = malloc(sizeof(t_token));
    if (!new_token)
        return (NULL);
    if (is_token(line[start]))
        new_token->value = ft_strnstr(line, line[start + 1], i - start - 1);
    else
        new_token->value = ft_strnstr(line, line[start], i - start);
    new_token->type = type;
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
