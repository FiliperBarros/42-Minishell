/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:18:47 by frocha-b          #+#    #+#             */
/*   Updated: 2026/01/27 17:11:52 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	is_all_digit(char *arg)
{
	int	i;

	i = 0;
	while(arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}


int parse_exit_value(const char *s, long long *out)
{
    int sign = 1;
    long long value = 0;
    int i = 0;

	if (!ft_strncmp(s,"-9223372036854775808", ft_strlen(s)))
		return (1);
    // Step 1 — optional sign
    if (s[i] == '+')
        i++;
    else if (s[i] == '-') {
        sign = -1;
        i++;
    }
	
    // Step 2 — must have at least one digit
    if (!isdigit(s[i]))
        return 0; // invalid numeric

    // Step 3 — accumulate digits safely
    while (s[i]) {
        if (!isdigit(s[i]))
            return 0; // invalid numeric

        int digit = s[i] - '0';

        // Check overflow
        if (value > (LLONG_MAX - digit) / 10)
            return 0; // overflow → invalid numeric

        value = value * 10 + digit;
        i++;
    }

    *out = value * sign;
    return 1; // success
}

//frees missing
void	ft_exit_builtin(int	is_fork, t_cmd *cmd, t_shell *shell)
{
	int	argc;
	long long	value;

	value = 0;
	argc = count_argv_strings(cmd->argv);
	if (cmd->argv[1] && ft_strncmp(cmd->argv[1], "--", ft_strlen(cmd->argv[1])) == 0)
		argc = 1;
	if (!(argc > 2 && is_all_digit(cmd->argv[1])))
	{
		if (is_fork)
			free_all(shell);
	}
	if (argc == 1)
		exit(shell->exit_status);
	if (argc > 2)
	{
		if (is_all_digit(cmd->argv[1]))
		{
			ft_printf("exit\n");
			write(2, "bash: exit: too many arguments\n", 31);
			shell->exit_status = 1;
			return ;
		}
		else
		{
			ft_printf("exit\n");
			write(2, "bash: exit: too many arguments\n", 31);
			shell->exit_status = 1;
			exit(2);
		}
	}
	if (argc == 2)
	{
		if (!parse_exit_value(cmd->argv[1], &value)) 
		{
    		ft_printf("exit\n");
			write(2, " numeric argument required\n", 27);
    		// ft_printf("minishell: exit: %s: numeric argument required\n", cmd->argv[1]);
    		if (!is_fork)
        		free_all(shell);
   		exit(2);
		}
		else
			exit((unsigned char) value);
	}
}

