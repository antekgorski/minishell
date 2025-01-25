/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2025/01/25 18:42:17 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int	is_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	handle_exit_error(t_minishell *minishell)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(minishell->cmd_list->argv[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	ft_shell_free(minishell);
	exit(2);
}

static long long	parse_exit_code(const char *str, t_minishell *minishell)
{
	long long	value;

	value = ft_atoll(str);
	if (value < INT_MIN || value > INT_MAX)
		handle_exit_error(minishell);
	return (value);
}

int	ft_exit(t_minishell *minishell)
{
	long long	exit_code;

	printf("exit\n");
	if (!minishell->cmd_list || !minishell->cmd_list->argv)
	{
		ft_shell_free(minishell);
		exit(0);
	}
	if (minishell->cmd_list->argv[1]
		&& !is_number(minishell->cmd_list->argv[1]))
		handle_exit_error(minishell);
	else if (minishell->cmd_list->argv[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		ft_shell_free(minishell);
		exit(1);
	}
	exit_code = parse_exit_code(minishell->cmd_list->argv[1], minishell);
	ft_shell_free(minishell);
	exit(exit_code % 256);
}
