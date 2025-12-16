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
    char            *value;
    t_tokentype     type;
    int             to_expand;
    int             to_contatenate_token;
    struct s_token  *next;
}   t_token;

typedef struct s_tokinfo
{
    int start;
    int end;
    int should_expand;
    int should_concatenate;
}   t_tokinfo;

/* ************************************************************************** */
/*                                                                            */
/*                                   Functions                                */
/*                                                                            */
/* ************************************************************************** */

t_token *lexer(char *line);
int     is_space(char c);
void    skip_with_quotes(char *line, int *i, int *error, t_tokinfo *token_info);
void    skip_without_quotes(char *line, int *i, t_tokinfo *token_info);
#endif

