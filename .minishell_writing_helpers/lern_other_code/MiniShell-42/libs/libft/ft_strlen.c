/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:54:23 by mjakowic          #+#    #+#             */
/*   Updated: 2024/03/05 14:48:34 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

//(17)- 'i' store the lenght of '*s'
//(19)- 'i' set to 0 as starting value.
//(20-23)- iterate till 's[i]' is nor NULL
//(24)return 'i'

/*
#include <stdio.h>

int	main(void)
{
	printf("%ld", ft_strlen("jhshshchs"));
	return (0);
}
*/