/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fursini <fursini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:59:25 by fursini           #+#    #+#             */
/*   Updated: 2023/01/25 14:44:46 by fursini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nstr(char const *s, char c)
{
	int	i;
	int	nstr;

	i = 0;
	nstr = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i] == 0)
				return (nstr);
			i++;
			if (s[i] == 0)
				return (nstr);
		}
		while (s[i] && s[i] != c)
			i++;
		nstr++;
		if (s[i] == 0)
			return (nstr);
		i++;
	}
	return (nstr);
}

static int	ft_start(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static int	ft_cstr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		nstr;
	int		cstr;
	int		start;
	char	**strs;
	int		i;

	start = 0;
	i = 0;
	if (!s)
		return (NULL);
	nstr = ft_nstr(s, c);
	while (s[start] && s[start] == c)
		start++;
	strs = (char **)malloc(sizeof(char *) * (nstr + 1));
	if (!strs)
		return (NULL);
	strs[nstr] = NULL;
	while (i < nstr)
	{
		cstr = ft_cstr(s + start, c);
		strs[i] = ft_substr(s, start, cstr);
		start += ft_start(s + start, c);
		i++;
	}
	return (strs);
}

// int main()
// {
// 	char **s = ft_split("lorem \"ipsum  ciao \"    dondisse", ' ');
// 	for(int i = 0; s[i]; i++)
// 		printf("%s\n", s[i]);
// }
