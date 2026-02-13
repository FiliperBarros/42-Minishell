/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:35:06 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/13 11:08:18 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "types.h"

struct	s_shell;

/* ---------------------------- EXEC CONTEXT ---------------------------- */
typedef struct s_exec_ctx
{
	struct s_shell	*shell;
	t_cmd			*cmd;
	int				**pipes;
	int				pipes_qnty;
	int				current;
	pid_t			last_pid;
}	t_exec_ctx;

/* ---------------------------- UTILS ---------------------------- */
int				count_cmds(t_cmd *cmd);
void			ft_exit_silent(struct s_shell *shell);

/* ---------------------------- EXECUTOR ---------------------------- */
void			executor(struct s_shell *shell);
void			executor_parent(struct s_shell *shell);
void			executor_loop(t_exec_ctx *ctx);

/* ---------------------------- CHILD EXECUTION ---------------------------- */
void			exec_child(t_exec_ctx *ctx, t_cmd *cmd, char *path);
void			exec_builtin_in_child(t_cmd *cmd, struct s_shell *shell);
pid_t			create_child(t_exec_ctx *ctx, t_cmd *cmd);

/* ---------------------------- PIPES ---------------------------- */
int				**alloc_pipes(int pipes_qnty);
void			free_pipes(int **pipes, int pipes_qnty);
void			setup_pipe_fds(int **pipes, int pipes_qnty, int i);
void			close_parent_pipes(int **pipes, int pipes_qnty, int i);
void			close_all_pipes(int **pipes, int pipes_qnty);

/* ---------------------------- REDIRECTIONS ---------------------------- */
int				apply_redirections(t_redir *redir);
int				apply_redirections_parent(t_redir *redir);

/* ---------------------------- HEREDOC ---------------------------- */
int				prepare_all_heredocs(struct s_shell *shell, t_cmd *cmd);
void			create_heredoc(struct s_shell *shell, t_redir *r);
char			*expand_heredoc(struct s_shell *shell, char *line);
char			*expand_env_var_for_heredoc(char **dollar_pos,
					struct s_shell *shell);

/* ---------------------------- FD BACKUP ---------------------------- */
t_std_backup	backup_std_fds(void);
void			restore_std_fds(t_std_backup b);

/* ---------------------------- EXIT STATUS ---------------------------- */
void			update_exit_status(struct s_shell *shell, int status);

/* ---------------------------- PATH ---------------------------- */
char			*solve_cmd_path(struct s_shell *shell, char *cmd_name);
int				handle_cmd_path(t_exec_ctx *ctx, char *cmd_name, char **path);

/* ---------------------------- PARENT EXECUTION LOGIC ----------------------*/
int				must_execute_in_parent(t_cmd *cmd);

#endif
