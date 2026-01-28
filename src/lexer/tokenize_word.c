#include "minishell.h"

static void	skip_with_quotes(char *line, int *i, t_tokinfo *info)
{

    info->quote_type = line[*i];
    (*i)++;
    while (line[*i] && line[*i] != info->quote_type)
        (*i)++;
    if (line[*i] && line[*i] == info->quote_type)
        (*i)++;
}

static void	skip_without_quotes(char *line, int *i)
{
    while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]) && !is_quote(line[*i]))
        (*i)++;
}
void    tokenize_word(char *line, t_token **new_token, int *i)
{
    t_tokinfo   info;

    ft_bzero(&info, sizeof(t_tokinfo));
    info.token_type = WORD;
    info.start = *i;
    if (is_quote(line[*i]))
        skip_with_quotes(line, i, &info);
    else
        skip_without_quotes(line, i);
    info.end = *i;
    info.to_concat = line[*i] && !is_space(line[*i]) && !is_operator(line[*i]);
    *new_token = create_token(line, &info);
}
