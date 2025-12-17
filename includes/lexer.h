#ifndef LEXER_H
#define LEXER_H

typedef enum e_tokentype
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC
}   t_tokentype;

/* ************************************************************************** */
/*                                                                            */
/*                                   Structs                                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_token
{
    t_tokentype     type;
    char            *value;
    int             len;
    char            quote_type;
    struct s_token  *next;
}   t_token;

typedef struct s_tokinfo
{
    int     start;
    int     end;
    char    quote_type;
    t_tokentype     token_type;
}   t_tokinfo;

/* ************************************************************************** */
/*                                                                            */
/*                                   Functions                                */
/*                                                                            */
/* ************************************************************************** */

void    lexer(t_token **tokens, char *line);
int     is_space(char c);
int     is_operator(char c);
int     is_quote(char c);
t_token *create_token(char *line, t_tokinfo info);
void    skip_with_quotes(char *line, int *i, int *error, t_tokinfo *token_info);
void    skip_without_quotes(char *line, int *i);
void    tokenize_operator(char *line, t_token *new_token, int *i);
void    tokenize_word(char *line, t_token *new_token, int *i);
void    add_token(t_token **tokens, t_token *new_token);
#endif

