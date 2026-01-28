#ifndef PARSER_H
# define PARSER_H

# include "types.h"

struct s_shell;

int		parser(struct s_shell *shell);
int		validate_syntax(t_token *tokens);
void	parsing(t_cmd **cmds, t_token *tokens);
int	    is_redir(int type);

#endif
