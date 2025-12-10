
void    skip_quotes(char *line, int *i)
{
    char quote;

    quote = line[*i];
    (*i)++;
    while (line[*i] && line[*i] != quote)
        (*i)++;
    if (line[*i] && line[*i] == quote)
        (*i)++;
}

t_token *tokenize_word(char *line, int *i, t_token **tokens)
{
    int start;
    int single_q;
    int double_q;

    start = *i;
    single_q = 0;
    double_q = 0;
    while (line[*i] && !is_space(line[*i]) && !is_operator(line[*i]))
    {
        if (line[*i] == '\'')
        {
            single_q = 1;
            *i = skip_quotes(line, i);
        }
        else if (line[*i] == '"')
        {
            double_q = 1;
            *i = skip_quotes(line, i);
        }
        else
            (*i)++;
    }
}