#include "minishell.h"

int is_operator(char c)
{
    return (c == '|' || c == '>' || c == '<');
}

t_token *lexer(char *line)
{
    int i;
    t_token *tokens;

    i = 0;
    tokens = NULL;
    while (line[i])
    {
        if(is_space(line[i]))
            i++;
        if (is_operator(line[i]))
            tokenize_operator(line, &i, &tokens);
        else
            tokenize_word(line, &i, &tokens);
        i++;
    }
    return (tokens);
}