#include "minishell.h"

static void	skip_without_quotes(char *line, int *i)
{
	while (line[*i] && !is_space(line[*i]))
		(*i)++;
}
static void    tokenize_expander(char *line, t_token **new_token, int *i)
{
    t_tokinfo   info;
	
    ft_bzero(&info, sizeof(t_tokinfo));
    info.token_type = WORD;
    info.start = *i;
    skip_without_quotes(line, i);
    info.end = *i;
    *new_token = create_token(line, &info);
	(*new_token)->value = ft_substr(line, info.start, info.end - info.start);
}

void	split_expanded_tokens(t_token **tokens_expanded, char *line)
{
	int	i;
	t_token *new_token;

	new_token = NULL;
	i = 0;
	while (line[i])
	{
		if(is_space(line[i]))
		{
			i++;
			continue;
		}
	tokenize_expander(line, &new_token, &i);
	add_token(tokens_expanded, new_token);
	}
}
