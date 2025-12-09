#ifndef LEXER_H
#define LEXER_H

typedef enum    e_tokentype
{
    WORD,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    REDIR_APPEND,
    HEREDOC,
} t_tokentype;

typedef struct s_token
{
    char *value;
    t_tokentype type;
    struct s_token *next;
}   t_token;