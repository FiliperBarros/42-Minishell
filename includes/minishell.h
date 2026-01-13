#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "colors.h"
#include "lexer.h"


typedef enum e_syntax_expect
{
    EXPECT_COMMAND,
    EXPECT_OPERATOR,
}   t_syntax_expect;

typedef	struct s_env
{
	char *key;
	char *value;
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
void	free_split(char	**split_str);
void	free_all(t_token *tokens, char *line);

//env
void	extract_value_key_from_envp(char *s, char **k, char **v);
void	env_from_envp(t_env **env, char **envp);
char	**env_to_envp(t_env *env);


//expander
void	split_expanded_tokens(t_token **tokens, char *line);
void	expander_and_concatenater(t_shell *shell, t_token	**tokens);
void	check_and_split_expanded_tokens(t_token **tk_list, t_token *t);
void	del_token(t_token *token, void (*del)(void *));
void	del_and_link_token(t_token **token, t_token *del_t);
char	*get_expand_value(char **dollar_pos, t_shell *shell, t_token *t);

//sucatadas
size_t	ft_strlen_mod(const	char *s);
char	*ft_strdup_mod(const char *s);
char	*ft_strjoin_mod(char const *s1, char const *s2);

int		is_redir(int type);
void	expand(t_token **tokens, t_shell *shell, t_token *t);

//parser
int		validate_syntax(t_token *t);
void	parser(t_cmd **cmd, t_token *t);

//utils
void	sigint_handler(int sig);
void	executor_simple(t_env *env, t_cmd *cmd);
char	*ft_strjoin3(char	*first_str, char *second_str, char *third_str);


#endif
