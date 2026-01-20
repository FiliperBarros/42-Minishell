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

typedef enum e_builtintype
{
    NOT_BUILTIN,
    ECHO,
    CD,
    PWD,
    EXPORT,
    UNSET,
    ENV,
    EXIT
}   t_builtintype;

/* ************************************************************************** */
/*                                                                            */
/*                                   Structs                                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_redir
{
    int             type;
    char            *filename;
    char            filename_quote;
    int             heredoc_fd;
    struct s_redir  *next;
}   t_redir;

typedef struct  s_cmd
{
    char            **argv;
    t_redir         *redirs;
    t_builtintype   builtin_type;
    struct s_cmd    *next;
}   t_cmd;

typedef struct s_token
{
    t_tokentype     type;
    char            *value;
    int             len;
    char            quote_type;
    int             to_concatenate;
    int             redir_delimiter;
    struct s_token  *next;
}   t_token;

typedef struct s_tokinfo
{
    int             start;
    int             end;
    char            quote_type;
    int             to_concat;
    t_tokentype     token_type;
}   t_tokinfo;

typedef struct s_std_backup
{
    int stdin_backup;
    int stdout_backup;
} t_std_backup;



/* ************************************************************************** */
/*                                                                            */
/*                                   Functions                                */
/*                                                                            */
/* ************************************************************************** */

void    lexer(t_token **tokens, char *line);
int     is_space(char c);
int     is_operator(char c);
int     is_quote(char c);
t_token *create_token(char *line, t_tokinfo *info);
void    tokenize_operator(char *line, t_token **new_token, int *i);
void    tokenize_word(char *line, t_token **new_token, int *i);
void    add_token(t_token **tokens, t_token *new_token);

int		to_expand(t_token *t);
void	lexer_expander(t_token **tokens, char *line);
#endif



