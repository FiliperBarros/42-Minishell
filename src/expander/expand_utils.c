#include "minishell.h"

int		to_expand(t_token *t)
{
	return (ft_strrchr(t->value, '$') && t->quote_type != '\'' && t->type == WORD && !t->heredoc_delimiter);
}

void	check_empty_quotes(t_token *tok)
{
	char	*empty_token;

	empty_token = malloc(1);
	empty_token[0] = '\0';
	if (tok->quote_type && tok->len == 2)
	{
		tok->value = empty_token;
		tok->len = 1;
	}
}

void	flag_heredoc_delimiter(t_token *t)
{
	if (t->next->type == WORD)
		t->next->heredoc_delimiter == 1;
}
void	remove_quotes(t_token *t)
{
	malloc(t->len)
	t->value = (t->value)++;
	t->len = ft_strlen(t->value) - 2;
}

void	expand_exit_code(t_token *t, t_shell *shell)
{
	t->value = ft_itoa(shell->exit_status);
	t->len = ft_strlen(t->value);
}

void	reflag_heredoc_delimiter(t_token *t)
{
	if (t->next)
		t->next->heredoc_delimiter = 1;
}