/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wildcards.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehosaf <sehosaf@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:06:56 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/17 14:26:55 by sehosaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		validate_asterisk(const char *arg, const char *asterisk);
static t_list	*get_args_list(char *arg, char *astr);
static void		fill_ast_args(char **ast_args, t_list *args_list);
static void		replace_asterisk(char ***old_args_p, int pos, char **args);

void	replace_wildcards(t_pipeline *node)
{
	int		i;
	char	*asterisk;
	t_list	*args_list;
	char	**ast_args;

	i = -1;
	while (node->cmd.args[++i])
	{
		asterisk = ft_strchr(node->cmd.args[i], '*');
		if (asterisk && validate_asterisk(node->cmd.args[i], asterisk))
		{
			args_list = get_args_list(node->cmd.args[i], asterisk);
			if (ft_lstsize(args_list))
			{
				ast_args = malloc(sizeof(char *) * (ft_lstsize(args_list) + 1));
				if (ast_args)
				{
					fill_ast_args(ast_args, args_list);
					replace_asterisk(&node->cmd.args, i, ast_args);
					i += ft_lstsize(args_list) - 1;
				}
			}
			ft_lstclear(&args_list, free);
		}
	}
}

/*
	Simple validation of asterisk.
	Valid only if out of any type of quotes.
*/
static int	validate_asterisk(const char *arg, const char *asterisk)
{
	int	sq;
	int	dq;
	int	i;

	i = 0;
	sq = 0;
	dq = 0;
	while (arg + i < asterisk)
	{
		if (arg[i] == '\'')
			sq++;
		else if (arg[i] == '"')
			dq++;
		i++;
	}
	if ((sq % 2) || (dq % 2))
		return (0);
	return (1);
}

static t_list	*get_args_list(char *arg, char *astr)
{
	t_list			*res;
	char			*dirname;
	DIR				*dirstream;
	struct dirent	*_dirent;

	res = NULL;
	dirname = getcwd(NULL, 0);
	dirstream = opendir(dirname);
	free(dirname);
	if (!dirstream)
		return (0);
	_dirent = readdir(dirstream);
	while (_dirent)
	{
		if ((size_t)(astr - arg) <= ft_strlen(_dirent->d_name)
			&& !ft_memcmp(_dirent->d_name, arg, astr - arg)
			&& ft_strlen(astr + 1) <= ft_strlen(_dirent->d_name)
			&& !ft_memcmp(_dirent->d_name + ft_strlen(_dirent->d_name)
				- ft_strlen(astr + 1), astr + 1, ft_strlen(astr + 1)))
			ft_lstadd_back(&res, ft_lstnew(ft_strdup(_dirent->d_name)));
		_dirent = readdir(dirstream);
	}
	closedir(dirstream);
	return (res);
}

static void	fill_ast_args(char **ast_args, t_list *args_list)
{
	int	i;

	i = 0;
	while (args_list)
	{
		ast_args[i] = ft_strdup(args_list->content);
		args_list = args_list->next;
		i++;
	}
	ast_args[i] = NULL;
}

static void	replace_asterisk(char ***old_args_p, int pos, char **args)
{
	char	**old_args;
	char	**new_args;
	int		s_old;
	int		s_ast;

	old_args = *old_args_p;
	s_old = get_split_size(old_args);
	s_ast = get_split_size(args);
	new_args = malloc(sizeof(char *) * (s_old + s_ast));
	if (new_args)
	{
		ft_memcpy(new_args, old_args, sizeof(char *) * pos);
		ft_memcpy(new_args + pos, args, sizeof(char *) * s_ast);
		ft_memcpy(new_args + pos + s_ast, old_args + pos
			+ 1, sizeof(char *) * (s_old - pos - 1));
		new_args[s_old + s_ast - 1] = NULL;
		free(old_args[pos]);
		free(old_args);
		*old_args_p = new_args;
	}
	free(args);
}
