/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:39:45 by fursini           #+#    #+#             */
/*   Updated: 2024/05/25 15:04:47 by fcorvaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Checks if a string can be converted to a long long integer.
 * 
 * @param str The string to check.
 * @return true If the string can be converted to a long long integer.
 * @return false Otherwise.
 */
static bool	is_longlong(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (is_toolong(str))
		return (false);
	return (true);
}

bool	is_toolong(char *str)
{
	long long	nbr;
	int			n;

	n = 0;
	nbr = 0;
	if (ft_strlen(str) > 20)
		return (true);
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (false);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			nbr = -1;
		str++;
	}
	while (*str)
	{
		n = *str - '0';
		if (nbr > (LLONG_MAX - n) / 10)
			return (true);
		nbr = nbr * 10 + n;
		str++;
	}
	return (false);
}

/**
 * @brief Exits the minishell program.
 * 
 * @param shell The minishell structure.
 * @param cmd The command structure.
 */
void	exit_minishell(t_minishell *shell, t_command *cmd)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (cmd && cmd->args[1])
	{
		if (cmd->args[2])
		{
			print_error("exit: too many arguments");
			g_exit_status = 1;
			return ;
		}
		else if (is_longlong(cmd->args[1]))
			g_exit_status = atoll(cmd->args[1]);
		else
		{
			g_exit_status = 2;
			print_error("exit: numeric argument required");
		}
		free_minishell(shell);
	}
	g_exit_status = 0;
	free_minishell(shell);
}
