
#include "minishell.h"

int	main(int ac, char **argv, char **envp)
{
	(void) ac;
	(void)argv;
	t_shell	shell;
	char 	*line;
	t_token *tokens;

	shell.env = NULL;
	shell.exit_status = 0;
	env_from_envp(&shell.env, envp);	
	while (1)
	{
		tokens = NULL;
		//meter tudo numa struct depois so das NULL a struct, q da null a tudo
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
		if (!line)
			return (1);
		else
			add_history(line);
		lexer(&tokens, line);
		expander(shell.env, &tokens);
		//concatenate_tokens(&tokens);
		print_tokens(tokens);

		// tokens = expand(line);

		// if(syntax_error(tokens))
		// 	continue;

		// cmd_tree = parse(tokens);

		// exec(cmd_tree);
		
		// free_all(tokens, cmd_tree, line);
		 free_tokens(&tokens);	
	}
		return (0);
}






