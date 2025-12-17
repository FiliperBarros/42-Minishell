#include "minishell.h"

void    lexer(t_token **tokens, char *line)
{
    int i;
    t_token *new_token;

    i = 0;
    new_token = NULL;
    while (line[i])
    {
        if(is_space(line[i]))
            i++;
        if (is_operator(line[i]))
            tokenize_operator(line, new_token, &i);
        else
            tokenize_word(line, new_token, &i);
        add_token(tokens, new_token);
    }
}
