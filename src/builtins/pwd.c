
#include "minishell.h"

int	ft_pwd()
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("pwd");
		return (1);
	}
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}

