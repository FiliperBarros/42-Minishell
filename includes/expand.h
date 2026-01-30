/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:47:13 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 14:06:29 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "types.h"

struct	s_shell;
struct	s_env;

/* main expansion */
void	expand(t_token **tokens, struct s_shell *shell, t_token *t);

/* word expansion */
char	*expand_word(char *value, int len, struct s_shell *shell,
			char quote_type, int exec);

/* helpers */
char	*expand_env_var(char **dollar_pos, struct s_shell *shell,
			char token_quote_type);
char	*expand_dollar(struct s_env *env,
			char *current_pos, char **dollar_pos);
char	*expand_pid(void);
char	*expand_tilde(struct s_shell *shell, char *value);

/* concatenation */
void	append_expansion(char **final_str, char **dollar_pos,
			struct s_shell *shell, char quote_type, int exec);
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
