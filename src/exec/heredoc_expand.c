/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:33:49 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/16 11:55:10 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env_var_for_heredoc(char **dollar_pos, t_shell *sh)
{
	char	*value;
	char	*after;

	value = NULL;
	after = ++(*dollar_pos);
	if (ft_isalpha(*after) || *after == '_')
		value = expand_dollar(sh->env, after, dollar_pos);
	else if (*after == '?')
		value = ft_itoa(sh->exit_status);
	else if (*after == '$')
		value = expand_pid();
	else if (is_space(*after) || !(*after) || is_quote(*after))
		value = ft_strdup("$");
	return (value);
}

char	*expand_heredoc(t_shell *sh, char *line)
{
	t_expand_ctx	ctx;
	char			*new_line;

	if (!ft_strchr(line, '$'))
		return (line);
	ctx.shell = sh;
	ctx.quote_type = '\0';
	ctx.exec = 1;
	new_line = expand_word(line, ft_strlen(line), &ctx);
	free(line);
	return (new_line);
}
