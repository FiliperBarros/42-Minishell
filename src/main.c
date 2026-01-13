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
	while (1)
	{
		line = NULL;
		signal(SIGINT, sigint_handler);
		// signal(SIGQUIT, print_exit);
		cmd = NULL;
		tokens = NULL;
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
 		if (!*line)
			continue;
		else
			add_history(line);
		lexer(&tokens, line);
		if (!tokens)
		{
			free_all(tokens, line);
			printf("minishell: syntax error: unclosed quotes\n");
			continue;
		}
		expander_and_concatenater(&shell, &tokens);
		if (validate_syntax(tokens))
		{
			free_all(tokens, line);
			continue;
		}
		parser(&cmd, tokens);
		// print_cmds(cmd);
		executor_simple(shell.env, cmd);
		// exec(cmd_tree);
		free_all(tokens, line);
	}
	free_env(shell.env);
	return (0);
}


