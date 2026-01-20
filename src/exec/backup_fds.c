#include "minishell.h"

t_std_backup	backup_std_fds()
{
	t_std_backup	b;

	b.stdin_backup = dup(STDIN_FILENO);
	b.stdout_backup = dup(STDOUT_FILENO);

	return (b);
}
void	restore_std_fds(t_std_backup b)
{
	dup2(b.stdin_backup, STDIN_FILENO);
	dup2(b.stdout_backup, STDOUT_FILENO);
	close(b.stdin_backup);
	close(b.stdout_backup);
}