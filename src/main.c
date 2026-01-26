#include "minishell.h"

int	main(int ac, char **argv, char **envp)
{
	(void) ac;
	(void)argv;
	t_shell	shell;
	char 	*line;
	t_token *tokens;
	t_cmd	*cmd;
	char	**my_envp;

	shell.env = NULL;
	shell.exit_status = 0;
	create_env_list(&shell.env, envp);
	//falta dar sort ao export para printar
	my_envp = env_to_envp(shell.env);
	while (1)
	{
		line = NULL;
		signal(SIGINT, sigint_prompt);
		signal(SIGQUIT, SIG_IGN);
		cmd = NULL;
		tokens = NULL;
		rl_event_hook = NULL;
		rl_on_new_line();
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
 		if (!line)
		{
			exit(0);
			break;
		}
		 	// ft_exit(0, cmd, &shell);
		 // check exit message when SHLVL = 0
		if (!*line)
		{
			free(line);
			continue;
		}
		else
			add_history(line);
		lexer(&tokens, line);
		if (!tokens)
		{
			free_all(cmd);
			free_tokens(tokens);
			printf("minishell: syntax error: unclosed quotes\n");
			continue;
		}
		expander_and_concatenater(&shell, &tokens);
		if (!tokens)
			continue;
		free(line);
		if (validate_syntax(tokens))
		{
			free_all(cmd);
			continue;
		}
		parser(&cmd, tokens);
		free_tokens(tokens);

		executor(&shell, cmd, my_envp);
		free_cmd(cmd);	
	}
	free_env(shell.env);
	free_double_char(my_envp);
	return (0);
}


