/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:47:13 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/04 12:44:34 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "types.h"

typedef struct s_expand_ctx
{
	struct s_shell	*shell;
	char	quote_type;
	int		exec;
}	t_expand_ctx;

/* main expansion */
void	expand(t_token **tokens, struct s_shell *shell, t_token *t);

/* word expansion */
char	*expand_word(char *value, int len, t_expand_ctx *ctx);

/* helpers */
char	*expand_env_var(char **dollar_pos, struct s_shell *shell,
			char token_quote_type);
char	*expand_env_var_for_heredoc(char **dollar_pos, struct s_shell *sh);
char	*expand_dollar(t_env *env, char *current_pos, char **dollar_pos);
char	*expand_pid(void);
char	*expand_tilde(struct s_shell *shell, char *value);

/* concatenation */
void	append_expansion(char **res, char **pos, t_expand_ctx *ctx);
void	append_literal(char **dst, char *start, char *end);
void	append_strings(char **final_str, char *env_value);

/* token split */
void	check_and_split_expanded_tokens(t_token **tk_list, t_token *t);
void	split_expanded_tokens(t_token **tokens, char *line);
void	expander_and_concatenater(struct s_shell *shell, t_token **tokens);

/* token utils */
void	del_token(t_token *token, void (*del)(void *));
void	del_and_link_token(t_token **token, t_token *del_t);

#endif
