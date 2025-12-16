#include "minishell.h"

void    lexer(t_token **tokens, char *line)
{
    int i;
    t_token new_token;

    i = 0;
    new_token = NULL;
    while (line[i])
    {
        if(is_space(line[i]))
            i++;
        if (is_operator(line[i]))
            new_token = tokenize_operator(line, &i, tokens);
        else
            new_token = tokenize_word(line, &i, tokens);
        add_token(tokens, new_token);
    }
}
