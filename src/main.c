
#include "minishell.h"

int	main(void)
{
	char *line;
	// t_token *tokens;
	
	while (1)
	{
		line = readline(RL_BLUE"minishell"RL_BOLD_RED "> "ANSI_RESET);
		if (!line)
			break;
		else
			add_history(line);
		tokens = lexer(line);

		// tokens = expand(line);

		// if(syntax_error(tokens))
		// 	continue;

		// cmd_tree = parse(tokens);

		// exec(cmd_tree);
		
		// free_all(tokens, cmd_tree, line);
	}
		return (0);
}
