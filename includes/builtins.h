#ifndef BUILTINS_H
# define BUILTINS_H

# include "types.h"

struct s_shell;
struct s_env;

/* builtin dispatch */
int		run_builtin(t_cmd *cmd, struct s_shell *shell, int is_fork);
void	exec_builtin(t_cmd *cmd);

/* builtins */
int		ft_cd(char **argv, struct s_env *env);
int		ft_echo(char **argv);
int		ft_env(struct s_env *env);
int		ft_pwd(void);
int		ft_export(t_cmd *cmd, struct s_env *env);
int		ft_unset(struct s_env *env, char **argv);
void	ft_exit_builtin(int is_fork, t_cmd *cmd, struct s_shell *shell);

/* export utils */
void	export_env(struct s_env **env, char *key, char *value);
int		update_existent_env(struct s_env *env,
			char *key, char *value, int append_flag);
void	get_key_and_value(struct s_env *env, char *arg,
			char **key, char **value);
int		is_valid_identifier(char *var_name);

#endif
