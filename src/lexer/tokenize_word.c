#include "minishell.h"

t_token   *tokenize_word(char *line, int *i)
{
    int         error;
    t_tokinfo   token_info;

    ft_bzero(token_info);
    error                   = 0;
    while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]))
    {
        if (is_quote(line[*i]))
        {
            skip_with_quotes(line, i, &error, &token_info);
            token_info->start       = *(i + 1);
            if(error)
                // return (printf("syntax error: unclosed quotes\n"), NULL);
        }
        else
        {
            skip_without_quotes(line, i, &token_info);
            token_info->start       = *i;
        }
        (*i)++;
    }
    token_info.should_expand = line[start] != '\'' && ft_strchr(line, "$");
    new_token = create_token(line, WORD, token_info);
}



