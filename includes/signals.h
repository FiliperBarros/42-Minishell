#ifndef SIGNALS_H
# define SIGNALS_H

void	set_prompt_signals(void);
void	set_exec_signals(void);
void	set_heredoc_signals(void);
void	reset_signals(void);

void	sigint_prompt(int sig);
void	sigint_heredoc(int sig);

#endif
