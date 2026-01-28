#include "minishell.h"

int main(int ac, char **argv, char **envp)
{
    (void)ac;
    (void)argv;

    t_shell shell;
	int		status;
    init_shell(&shell, envp);
    shell.my_envp = env_to_envp(shell.env);
    //update my_envp when export or unset or always envp inside the loop
    while (1)
    {
	    shell.line = NULL;
		shell.token = NULL;
    	shell.cmd = NULL;
        status = handle_input(&shell);
        if (status == 2)
            continue;
        if (!parser(&shell))
            continue;
        executor(&shell);
		free_all(&shell);
    }
    ft_exit(&shell);
    return (shell.exit_status);
}
