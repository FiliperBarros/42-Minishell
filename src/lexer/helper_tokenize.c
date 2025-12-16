int is_space(char c)
{
    return (c == ' ' ||(c >= 9 && c <= 13));
}

int is_operator(char c)
{
    return (c == '|' || c == '>' || c == '<');
}

int is_quote(char c)
{
    return (c == '"' || c == '\'');
}

static void     should_concatenate(int *concatenate, char c)
{
    *concatenate = (c && !is_space(c) && !is_operator(c));
}
