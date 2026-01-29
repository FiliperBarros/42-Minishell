#include "minishell.h"

char    **get_envp(t_shell *sh)
{
    if (!sh->my_envp || sh->envp_dirty)
    {
        free_double_char(sh->my_envp);
        sh->my_envp = env_list_to_envp(sh->env);
        sh->envp_dirty = 0;
    }
    return (sh->my_envp);
}
