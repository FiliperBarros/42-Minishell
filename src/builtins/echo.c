#include "minishell.h"

static int	check_newline_flag(char *str)
{
	return (ft_strncmp(str, "-n", 3) == 0);
}
int	ft_echo(char **argv)
{
	int	i;
	int	newline_flag;

	i = 1;
	newline_flag = check_newline_flag(argv[1]);
	if (newline_flag)
		i++;
	while (argv[i])
	{	
		ft_printf("%s", argv[i]);
		if (argv[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!newline_flag)
		ft_printf("\n");
	return (1);
}
