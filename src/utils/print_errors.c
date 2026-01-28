#include "minishell.h"

void	print_error(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
}
