#include "minishell.h"

void	sigint_prompt(int sig)
{
	(void) sig;
	write(1, "\n", 1);

	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}