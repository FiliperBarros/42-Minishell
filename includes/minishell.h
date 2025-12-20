#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "colors.h"
#include "lexer.h"

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
void	print_tokens(t_token *tokens);

//free
void	free_tokens(t_token **tokens);

//env
void	extract_value_key_from_envp(char *s, char **k, char **v);
void	env_from_envp(t_env **env, char **envp);

#endif
