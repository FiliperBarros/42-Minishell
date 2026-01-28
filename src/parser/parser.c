#include "minishell.h"

int parser(t_shell *shell)
{
    lexer(&shell->token, shell->line);
    if (!shell->token)
    {
        free_all(shell);
        print_error("minishell: syntax error: unclosed quotes\n");
        return (0);
    }
    expander_and_concatenater(shell, &shell->token);
    if (!shell->token)
        return (0);
    if (validate_syntax(shell->token))
    {
        shell->exit_status = 2;
        free_all(shell);
        return (0);
    }
    parsing(&shell->cmd, shell->token);
    return (1);
}
