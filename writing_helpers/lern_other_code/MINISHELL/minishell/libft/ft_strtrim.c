/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:58:36 by fursini           #+#    #+#             */
/*   Updated: 2023/01/25 22:17:21 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		head;
	int		tail;

	tail = 0;
	if (!s1)
		return (NULL);
	head = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	while (check(s1[tail], set) && s1[tail])
		tail++;
	while (head > tail && check(s1[head - 1], set))
		head--;
	str = (char *)malloc(sizeof(char) * (head - tail + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, (s1 + tail), head - tail);
	str[head - tail] = 0;
	return (str);
}

// int main()
// {
// 	char	s[] ="diomdiadonaddoi";
// 	char	*s2 = ft_strtrim(s, "dio");
// 	printf("%s\n", s2);
// }
