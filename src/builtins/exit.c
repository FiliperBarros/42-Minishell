/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:47 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/28 16:34:51 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_exit_value(const char *s, long long *out)
{
	long long	v;
	int			i;
	int			sign;

	v = 0;
	i = 0;
	sign = 1;
	if (!ft_strncmp(s, "-9223372036854775808", ft_strlen(s)))
		return (1);
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]) || v > (LLONG_MAX - (s[i] - '0')) / 10)
			return (0);
		v = v * 10 + (s[i] - '0');
		i++;
	}
	*out = v * sign;
	return (1);
}

static void	exit_numeric_error(int is_parent, t_shell *shell)
{
	ft_printf("exit\n");
	print_error(" numeric argument required\n");
	if (is_parent)
		free_all(shell);
	exit(2);
}

static void	print_too_many_args(t_shell *shell)
{
	ft_printf("exit\n");
	print_error("bash: exit: too many arguments\n");
	shell->exit_status = 1;
}

void	ft_exit_builtin(int is_parent, t_cmd *cmd, t_shell *shell)
{
	long long	val;
	int			ac;

	val = 0;
	ac = count_argv_strings(cmd->argv);
	if (ac == 2 && !ft_strncmp(cmd->argv[1], "--", ft_strlen(cmd->argv[1])))
		ac = 1;
	if (ac == 1)
		exit(shell->exit_status);
	if (ac == 2 && !parse_exit_value(cmd->argv[1], &val))
		exit_numeric_error(is_parent, shell);
	if (ac == 2)
		exit((unsigned char)val);
	if (ac > 2)
	{
		if (is_all_digit(cmd->argv[1]))
		{
			print_too_many_args(shell);
			return ;
		}
		exit_numeric_error(is_parent, shell);
	}
}
