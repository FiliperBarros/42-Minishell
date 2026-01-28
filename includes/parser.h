/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:45:53 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 17:45:54 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

struct	s_shell;

int		parser(struct s_shell *shell);
int		validate_syntax(t_token *tokens);
void	parsing(t_cmd **cmds, t_token *tokens);
int		is_redir(int type);

#endif
