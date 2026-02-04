/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:13:19 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 12:42:55 by frocha-b         ###   ########.fr       */
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

void	append_expansion(char **res, char **pos, t_expand_ctx *ctx)
{
	char	*val;

	if (ctx->exec)
		val = expand_env_var_for_heredoc(pos, ctx->shell);
	else
		val = expand_env_var(pos, ctx->shell, ctx->quote_type);
	append_strings(res, val);
}

char	*expand_word(char *val, int len, t_expand_ctx *ctx)
{
	char	*cur;
	char	*res;
	char	*end;
	char	*next;

	cur = val;
	if (ctx->quote_type == '\0' && *cur == '~')
		return (expand_tilde(ctx->shell, cur));
	res = NULL;
	end = val + len;
	while (cur < end)
	{
		next = ft_strchr(cur, '$');
		if (!next || next > end)
			next = end;
		append_literal(&res, cur, next);
		if (next < end && *next == '$')
			append_expansion(&res, &next, ctx);
		cur = next;
	}
	return (res);
}

void	expand(t_token **tokens, t_shell *shell, t_token *t)
{
	t_expand_ctx	ctx;

	ctx.shell = shell;
	ctx.quote_type = t->quote_type;
	ctx.exec = 0;
	t->value = expand_word(t->value, t->len, &ctx);
	t->len = ft_strlen_mod(t->value);
	if (!t->value || (!(*t->value) && !t->quote_type))
		return (del_and_link_token(tokens, t));
	check_and_split_expanded_tokens(tokens, t);
}
