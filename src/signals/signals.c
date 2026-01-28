#include "minishell.h"

void set_prompt_signals(void)
{
    signal(SIGINT, sigint_prompt);
    signal(SIGQUIT, SIG_IGN);
}

void set_exec_signals(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
}

void set_heredoc_signals(void)
{
    signal(SIGINT, sigint_heredoc);
    signal(SIGQUIT, SIG_IGN);
}

void reset_signals(void)
{
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void	sigint_prompt(int sig)
{
	(void) sig;
	write(1, "\n", 1);

	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void sigint_heredoc(int sig)
{
    (void)sig;
    write(1, "\n", 1);
    exit(130);
}
