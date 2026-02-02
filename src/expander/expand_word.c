/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:19 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/02 18:27:13 by frocha-b         ###   ########.fr       */
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

void	append_expansion(char **res, char **pos, t_shell *sh, char qt, int exec)
{
	char	*val;

	if (exec)
		val = expand_env_var_for_heredoc(pos, sh);
	else
		val = expand_env_var(pos, sh, qt);
	append_strings(res, val);
}

char	*expand_word(char *val, int l, t_shell *sh, char qt, int exec)
{
	char	*cur;
	char	*res;
	char	*end;
	char	*next;

	cur = val;
	if (qt == '\0' && *cur == '~')
		return (expand_tilde(sh, cur));
	res = NULL;
	end = val + l;
	while (cur < end)
	{
		next = ft_strchr(cur, '$');
		if (!next || next > end)
			next = end;
		append_literal(&res, cur, next);
		if (next < end && *next == '$')
			append_expansion(&res, &next, sh, qt, exec);
		cur = next;
	}
	return (res);
}

void	expand(t_token **tokens, t_shell *shell, t_token *t)
{
	t->value = expand_word(t->value, t->len, shell, t->quote_type, 0);
	t->len = ft_strlen_mod(t->value);
	if (!t->value || (!(*t->value) && !t->quote_type))
		return (del_and_link_token(tokens, t));
	check_and_split_expanded_tokens(tokens, t);
}
