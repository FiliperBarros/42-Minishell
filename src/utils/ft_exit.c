#include "minishell.h"

void ft_exit(t_shell *shell)
{
    free_all(shell);
    free_env(shell->env);
    free_double_char(shell->my_envp);
    printf("exit\n");
    exit(shell->exit_status);
}
