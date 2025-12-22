#include "minishell.h"

static void    detect_operator_type(t_tokinfo *info, char *line, int *i)
{
    if (line[*i] == '|')
    {   
        info->token_type = PIPE;
        (*i)++;
    }
    else if(line[(*i)] == '<')
    {
        if(line[*i] == line[++(*i)])
        {
            (*i)++;
            info->token_type = HEREDOC;
        }
        else
            info->token_type = REDIR_IN;
    }
    else if(line[(*i)] == '>')
    {
        if (line[*i] == line[++(*i)])
        {
            (*i)++;
            info->token_type = REDIR_APPEND;
        }
        else
            info->token_type = REDIR_OUT;
    }
}

void    tokenize_operator(char *line, t_token **new_token, int *i)
{
    t_tokinfo   info;

    ft_bzero(&info, sizeof(info));
    info.start = *i;
    detect_operator_type(&info, line, i);
    info.end = *i;
    *new_token = create_token(line, &info);
}


