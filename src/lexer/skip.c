   #include "minishell.h"
    
void    skip_with_quotes(char *line, int *i, int *error, t_tokinfo *info)
{

    info->quote_type = line[*i];
    (*i)++;
    while (line[*i] && line[*i] != info->quote_type)
        (*i)++;
    if (line[*i] && line[*i] == info->quote_type)
        (*i)++;
    else
        *error = 1;
}


void    skip_without_quotes(char *line, int *i)
{
    while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]))
        (*i)++;
}
