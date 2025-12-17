#include "minishell.h"

void    tokenize_word(char *line, t_token *new_token, int *i)
{
    int         error;
    t_tokinfo   info;

    error                   = 0;
    info.start              = *i;
    ft_bzero(&info, sizeof(info));
    info.token_type = WORD;
    while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]))
    {
        if (is_quote(line[*i]))
            skip_with_quotes(line, i, &error, &info);
        else
            skip_without_quotes(line, i);
        /* if(error)
            return (printf("syntax error: unclosed quotes\n"), NULL); */
    }
    info.end = *i;
    new_token = create_token(line, info);
}


void    tokenize_operator(char *line, t_token *new_token, int *i)
{
    t_tokinfo   info;

    info.start = *i;
    ft_bzero(&info, sizeof(info));
    if (line[*i] == '|')
        info.token_type = PIPE;
    if (line[*i] == '<')
    {
        if (line[*(++i)] == '<')
            info.token_type = HEREDOC;
        else
            info.token_type = REDIR_IN;
    }
    if (line[*i] == '>')
    {
        if (line[*(++i)] == '>')
            info.token_type = REDIR_APPEND;
        else
            info.token_type = REDIR_OUT;
    }
    info.end = *i;
    new_token = create_token(line, info);
}

