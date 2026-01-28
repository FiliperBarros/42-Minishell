/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:17:35 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:17:42 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

struct  s_shell;

size_t	ft_strlen_mod(const char *s);
char	*ft_strdup_mod(const char *s);
char	*ft_strjoin_mod(const char *s1, const char *s2);
char	*ft_strjoin3(char *s1, char *s2, char *s3);

int		count_argv_strings(char **argv);
void	print_error(char *error_msg);

/* free */
void	free_tokens(t_token *tokens);
void	free_env(t_env *env);
void	free_envp(char **envp);
void	free_double_char(char **split_str);
void	free_cmd(t_cmd *cmd);
void    free_all(struct s_shell *shell);

#endif
