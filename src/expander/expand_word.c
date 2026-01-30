/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:19 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 14:05:46 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append_literal(char **dst, char *start, char *end)
{
	char	*part;

	if (start >= end)
		return ;
	part = ft_substr(start, 0, end - start);
	append_strings(dst, part);
}

void	append_expansion(char **final_str, char **dollar_pos, t_shell *shell, char quote_type, int exec)
{
	char	*env_value;

	if (exec)
		env_value = expand_env_var_for_heredoc(dollar_pos, shell);
	else
		env_value = expand_env_var(dollar_pos, shell, quote_type);
	append_strings(final_str, env_value);
}

char	*expand_word(char *value, int len, t_shell *shell, char quote_type, int exec)
{
	char	*cursor;
	char	*final_str;
	char	*end;
	char	*next_dollar;

	cursor = value;
	if (quote_type == '\0' && *cursor == '~')
		return (expand_tilde(shell, cursor));
	final_str = NULL;
	end = value + len;
	while (cursor < end)
	{
		next_dollar = ft_strchr(cursor, '$');
		if (!next_dollar || next_dollar > end)
			next_dollar = end;
		append_literal(&final_str, cursor, next_dollar);
		if (next_dollar < end && *next_dollar == '$')
			append_expansion(&final_str, &next_dollar, shell, quote_type, exec);
		cursor = next_dollar;
	}
	return (final_str);
}

void	expand(t_token **tokens, t_shell *shell, t_token *t)
{
	t->value = expand_word(t->value, t->len, shell, t->quote_type, 0);
	t->len = ft_strlen_mod(t->value);
	if (!t->value || (!(*t->value) && !t->quote_type))
		return (del_and_link_token(tokens, t));
	check_and_split_expanded_tokens(tokens, t);
}
