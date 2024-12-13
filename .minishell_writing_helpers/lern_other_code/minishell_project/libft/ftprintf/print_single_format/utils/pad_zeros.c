/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoroz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:59:59 by dmoroz            #+#    #+#             */
/*   Updated: 2024/03/17 17:43:10 by dmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_single_format.h"

static void	helper(int expected_len, int len, char **num)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)malloc((expected_len - len + 1) * sizeof(char));
	if (!tmp1)
		return ;
	ft_memset(tmp1, '0', expected_len - len);
	tmp1[expected_len - len] = 0;
	tmp2 = ft_strjoin(tmp1, *num);
	free(tmp1);
	free(*num);
	*num = tmp2;
}

void	pad_zeros(t_foramt_config conf, char **num, int len, int is_neg)
{
	int	expected_len;

	expected_len = 0;
	if (conf.precision >= 0)
		expected_len = conf.precision;
	else if (conf.zero_padding && conf.min_width > 0 && !conf.left_adjusted)
	{
		expected_len = conf.min_width - (conf.force_sign + conf.space_before_pos
				+ is_neg > 0);
	}
	if (expected_len > len)
		helper(expected_len, len, num);
}
