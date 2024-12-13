/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:46 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 13:46:20 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *buf, int c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	if (c == '\0')
		return (buf + gnl_strlen(buf));
	while (buf[i])
	{
		if (buf[i] == c)
			return (&buf[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *buf, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!temp)
		return (0);
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char));
		buf[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(buf) + gnl_strlen(temp)
				+ 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (buf && buf[++i] != '\0')
		str[i] = buf[i];
	while (temp && temp[j] != '\0')
		str[i++] = temp[j++];
	str[i] = '\0';
	free(buf);
	return (str);
}
