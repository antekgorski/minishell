/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cmd_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:28:38 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/18 10:27:36 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "environment.h"

void	remove_cmd_arg(t_pipeline *node, int ind)
{
	free(node->cmd.args[ind]);
	while (node->cmd.args[ind])
	{
		node->cmd.args[ind] = node->cmd.args[ind + 1];
		ind++;
	}
}

/*
	Returns variable name. Result is dynamically allocated and should be freed.
	Input - pointer on `$` (char before variable name)
*/
char	*get_var_name(char *dollar)
{
	char	*res;
	int		i;

	if (dollar[1] == '?')
		i = 2;
	else
	{
		i = 1;
		while (ft_isalpha(dollar[i]))
			i++;
	}
	res = malloc(i);
	if (!res)
		return (NULL);
	ft_memcpy(res, dollar + 1, i - 1);
	res[i - 1] = 0;
	return (res);
}

char	*get_var_value(const char *name, t_shell *shell)
{
	char	*var_value;

	if (ft_memcmp(name, "?", 2) == 0)
		return (ft_itoa(shell->exit_status));
	var_value = get_env_val(shell->env, name);
	return (ft_strdup(var_value));
}
