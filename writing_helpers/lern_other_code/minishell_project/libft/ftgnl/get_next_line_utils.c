/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:18:09 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/07 18:18:39 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_strnjoin(char *line, char *buffer, unsigned int buff_n,
		unsigned int *line_size)
{
	char			*res;
	unsigned int	line_len;
	unsigned int	total_len;

	line_len = ft_strlen(line);
	total_len = line_len + buff_n + 1;
	if (total_len > *line_size)
	{
		*line_size *= 2;
		*line_size = *line_size * (*line_size > total_len)
			+ total_len * (*line_size <= total_len);
		res = (char *)malloc(*line_size * sizeof(char));
		if (!res)
			return (NULL);
		ft_memmove(res, line, line_len);
	}
	else
		res = line;
	ft_memmove(res + line_len, buffer, buff_n);
	res[total_len - 1] = 0;
	return (res);
}
