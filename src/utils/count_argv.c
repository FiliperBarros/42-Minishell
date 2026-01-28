#include "minishell.h"

int	count_argv_strings(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}