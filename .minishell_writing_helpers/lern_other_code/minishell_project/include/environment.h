/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <dmoroz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:18:03 by sehosaf           #+#    #+#             */
/*   Updated: 2024/07/08 16:00:40 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"
# include "libft.h"

//		** environment functions **
int		create_env_var(t_env **env, const char *key_value);
t_env	*create_env_node(char **key_value);

char	*get_env_val(t_env *env, const char *key);
int		set_env_var(t_env *env, const char *key, const char *value);
int		free_key_val(char **key_val, bool success);
int		overwrite_var(t_env *existing_node, char **key_val);
void	free_env(t_env *env);

t_env	*get_env_node(t_env *env, const char *key);
t_env	*get_last_node(t_env *env);
char	**split_key_value(const char *str, char c);
bool	is_valid_env_var(const char *str);
int		get_env_size(t_env *env);

#endif
