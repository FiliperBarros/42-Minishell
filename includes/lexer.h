#ifndef LEXER_H
# define LEXER_H

# include "types.h"

/* lexer core */
void	lexer(t_token **tokens, char *line);

/* tokenization */
void	tokenize_operator(char *line, t_token **new_token, int *i);
void	tokenize_word(char *line, t_token **new_token, int *i);
t_token	*create_token(char *line, t_tokinfo *info);
void	add_token(t_token **tokens, t_token *new_token);

/* utils */
int		is_space(char c);
int		is_operator(char c);
int		is_quote(char c);

/* expansion flags */
int		to_expand(t_token *t);

#endif
