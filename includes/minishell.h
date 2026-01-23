#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "colors.h"
#include "lexer.h"


typedef	struct s_env
{
	char 	*key;
	char 	*value;
	int		to_hide;
	struct s_env *next;
}	t_env;

typedef	struct s_shell
{
	t_env 	*env;
	int		exit_status;
}	t_shell;

//teste
void	print_tokens(t_token **tokens);
void 	print_cmds(t_cmd *cmds);

//free
void	free_tokens(t_token *tokens);
void	free_env(t_env *env);
void	free_double_char(char	**split_str);
void	free_envp(char **envp);
void	free_cmd(t_cmd *cmd);
void	free_all(t_cmd *cmd);

//env
void		get_env_from_envp(t_env **env, char **envp);
char		**env_to_envp(t_env *env);
t_env		*find_env_by_key(t_env *env, char *key_to_find);
void		env_add_node(t_env **env, t_env *env_node);


//expander
char	*expand_word(char *value, int len, t_shell *shell, char quote_type, int exec);
void	split_expanded_tokens(t_token **tokens, char *line);
void	expander_and_concatenater(t_shell *shell, t_token	**tokens);
void	check_and_split_expanded_tokens(t_token **tk_list, t_token *t);
void	del_token(t_token *token, void (*del)(void *));
void	del_and_link_token(t_token **token, t_token *del_t);
char	*get_expand_value(char **dollar_pos, t_shell *shell, char token_quote_type);
char	*get_env_value(t_env *env, char *current_pos, char **dollar_pos);
char	*get_pid_value();

//append
void	append_expansion(char **final_str, char **dollar_pos, t_shell *shell,char quote_type, int exec);
void	append_literal(char **dst, char *start, char *end);
void	append_strings(char **final_str, char *env_value);

//utils
size_t	ft_strlen_mod(const	char *s);
char	*ft_strdup_mod(const char *s);
char	*ft_strjoin_mod(char const *s1, char const *s2);

int		is_redir(int type);
void	expand(t_token **tokens, t_shell *shell, t_token *t);

//parser
int		validate_syntax(t_token *t);
void	parser(t_cmd **cmd, t_token *t);

//utils
void	print_std_error(char *error_msg);
void	sigint_prompt(int sig);
void	executor(t_shell *shell, t_cmd *cmd, char **envp);
char	*ft_strjoin3(char	*first_str, char *second_str, char *third_str);

//exec
char	*get_expand_value_for_heredoc(char **dollar_pos, t_shell *shell);
void	create_heredoc(t_shell *shell, t_redir *r);

//pipes
void	open_pipes(int	pipes[][2], int pipes_qnty);
void	close_pipe(int pipes[]);
void	close_all_pipes(int pipes[][2], int pipes_qnty);
void	close_parent_pipes(int pipes[][2], int pipes_qnty, int i);
void	setup_pipe_fds(int pipes[][2], int pipes_qnty, int i);

//status
void	update_exit_status(t_shell *shell, int	status);

void	run_cmd(t_cmd *cmd, int pipes[][2], int pipes_qnty, int i, char **envp, char *path, t_shell *shell);
void	run_builtin_in_parent(t_cmd *cmd, t_shell *shell);
void	run_builtin_in_fork(t_cmd *cmd, t_shell *shell);
void	run_cmd(t_cmd *cmd, int pipes[][2], int pipes_qnty, int i, char **envp, char *path, t_shell *shell);
void	apply_redirections(t_redir *redir);
void	exec_builtin(t_cmd *cmd);
int		run_builtin(t_cmd *cmd, t_shell *shell, int is_fork);

//builtins
int		ft_echo(char **argv);
void	ft_exit(int is_fork, t_cmd *cmd, t_shell *shell);
int		ft_env(t_env *env);
int		ft_pwd(t_env *env);
int		ft_export(t_cmd *cmd, t_env *env);
int		ft_unset(t_env *env, char **argv);

int		update_existent_env(t_env *env, char *key, char *value, int append_flag);
void	set_env(t_env **env, char *key, char *value, int append_flag);
void	split_key_value(char *arg, char **key, char **value, int *append_flag);
int		is_valid_identifier(char *var_name);

//path
char			*solve_cmd_path(t_shell *shell, char *cmd_name);

//backup fds
t_std_backup	backup_std_fds();
void			restore_std_fds(t_std_backup b);

//exec_parent
void	executor_parent(t_shell *shell, t_cmd *cmd);
int		should_run_in_parent(t_cmd *cmd);


//env


#endif
