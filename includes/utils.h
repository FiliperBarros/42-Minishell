/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:34:53 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 17:34:55 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "types.h"

struct  s_shell;

size_t  ft_strlen_mod(const char *s);
char    *ft_strdup_mod(const char *s);
char    *ft_strjoin_mod(const char *s1, const char *s2);
char    *ft_concat_three(char *s1, char *s2, char *s3);

int     count_argv_strings(char **argv);
void    print_error(char *error_msg);

/* token */
t_token *token_last(t_token *lst);
t_token *token_prev(t_token *head, t_token *target);

/* free */
void    free_tokens(t_token **tokens);
void    free_env(t_env *env);
void    free_envp(char **envp);
void    free_double_char(char ***split_str);
void    free_cmd(t_cmd **cmd);
void    free_all(struct s_shell *shell);
void    free_redirs(t_redir **redirs);

#endif