/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:45:48 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/18 16:15:35 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_tokentype
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC
}	t_tokentype;

typedef enum e_builtintype
{
	NOT_BUILTIN,
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtintype;

typedef struct s_redir
{
	int				type;
	char			*filename;
	char			filename_quote;
	int				heredoc_fd;
	int				heredoc_error;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**argv;
	t_redir			*redirs;
	t_builtintype	builtin_type;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_token
{
	t_tokentype		type;
	char			*value;
	int				len;
	char			quote_type;
	int				to_concatenate;
	int				redir_delimiter;
	struct s_token	*next;
}	t_token;

typedef struct s_tokinfo
{
	int				start;
	int				end;
	char			quote_type;
	int				to_concat;
	t_tokentype		token_type;
}	t_tokinfo;

typedef struct s_std_backup
{
	int	stdin_backup;
	int	stdout_backup;
}	t_std_backup;

#endif
