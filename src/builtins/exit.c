/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:47 by frocha-b          #+#    #+#             */
/*   Updated: 2026/02/18 11:39:54 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	exit_err(t_shell *sh, char *arg)
{
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	sh->exit_status = 2;
	ft_exit_silent(sh);
}

void	ft_exit_builtin(int is_parent, t_cmd *cmd, t_shell *sh)
{
	long long	val;
	int			ac;

	val = 0;
	ac = count_argv_strings(cmd->argv);
	if (is_parent)
		ft_putstr_fd("exit\n", 2);
	if (ac == 1 || ((ac == 2 && ft_strncmp(cmd->argv[1], "--", 3) == 0)))
		ft_exit_silent(sh);
	if (!parse_exit_value(cmd->argv[1], &val))
		exit_err(sh, cmd->argv[1]);
	if (ac > 2)
	{
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		sh->exit_status = 1;
		return ;
	}
	sh->exit_status = (unsigned char)val;
	ft_exit_silent(sh);
}
