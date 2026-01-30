/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:47:05 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/30 15:13:44 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "types.h"

struct	s_shell;

int	count_cmds(t_cmd *cmd);
/* executor */
void	executor(struct s_shell *shell);
void	executor_parent(struct s_shell *shell);

/* commands */
void	exec_child(t_cmd *cmd, int pipes[][2], int pipes_qnty,
			int i, char *path, struct s_shell *shell);
void	exec_builtin_in_child(t_cmd *cmd, struct s_shell *shell);

/* pipes */
void	open_pipes(int pipes[][2], int pipes_qnty);
void	close_pipe(int pipes[2]);
void	close_all_pipes(int pipes[][2], int pipes_qnty);
void	close_parent_pipes(int pipes[][2], int pipes_qnty, int i);
void	setup_pipe_fds(int pipes[][2], int pipes_qnty, int i);

/* redirections */
int	apply_redirections_parent(t_redir *redir);
void	apply_redirections(t_redir *redir);

/* heredoc */
int		prepare_all_heredocs(struct s_shell *shell, t_cmd *cmd);
void	create_heredoc(struct s_shell *shell, t_redir *r);
char	*expand_heredoc(struct s_shell *shell, char *line);
char	*expand_env_var_for_heredoc(char **dollar_pos,
			struct s_shell *shell);

/* fd backup */
t_std_backup	backup_std_fds(void);
void	restore_std_fds(t_std_backup b);

/* status */
void	update_exit_status(struct s_shell *shell, int status);

/* path */
char	*solve_cmd_path(struct s_shell *shell, char *cmd_name);
int		handle_cmd_path(struct s_shell *shell, char *cmd_name, char **path, int pipes[][2], int pipes_qnty);

/* parent logic */
int		must_execute_in_parent(t_cmd *cmd);

#endif
