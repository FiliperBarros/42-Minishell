#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include <readline/readline.h>
# include <readline/history.h>

# include "types.h"
# include "env.h"
# include "lexer.h"
# include "parser.h"
# include "expand.h"
# include "exec.h"
# include "builtins.h"
# include "utils.h"
# include "signals.h"
# include "colors.h"

typedef struct s_shell
{
	t_token	*token;
	t_cmd	*cmd;
	t_env	*env;
	char	**my_envp;
	char	*line;
	int		exit_status;
}	t_shell;

/* init */
void	init_shell(t_shell *shell, char **envp);
int		handle_input(t_shell *shell);
void	ft_exit(t_shell *shell);

/* debug */
void	print_tokens(t_token **tokens);
void	print_cmds(t_cmd *cmds);

#endif
