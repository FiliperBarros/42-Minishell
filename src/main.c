#include "minishell.h"

int	main(int ac, char **argv, char **envp)
{
	(void) ac;
	(void)argv;
	t_shell	shell;
	char 	*line;
	t_token *tokens;
	t_cmd	*cmd;

	shell.env = NULL;
	shell.exit_status = 0;
	env_from_envp(&shell.env, envp);	
	if (1)
	{
		line = NULL;
		signal(SIGINT, sigint_handler);
		// signal(SIGQUIT, print_exit);
		cmd = NULL;
		tokens = NULL;
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
 		if (!*line)
			return (1);
		else
			add_history(line);
		lexer(&tokens, line);
		if (!tokens)
		{
			free_all(tokens, line);
			printf("minishell: syntax error: unclosed quotes\n");
			return (1);
		}
		expander_and_concatenater(&shell, &tokens);
		if (validate_syntax(tokens))
		{
			free_all(tokens, line);
			return (1);
		}
		parser(&cmd, tokens);
		// // print_cmds(cmd);
		executor(&shell, cmd);
		free_all(tokens, line);
		free_cmd(cmd);
	}
	free_env(shell.env);
	return (0);
}


