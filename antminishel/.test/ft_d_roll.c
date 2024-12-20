#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

// cc ft_d_roll.c -L ../libft -lft -g

void	ft_d_roll(char **in_d_quote)
{
	char	*temp;
	char	*result;
	char	*q_line;
	int		s;
	int		m;
	int		flag;

	result = NULL;
	s = 0;
	m = 0;
	flag = 0;
	q_line = *in_d_quote;
	while (q_line[m])
	{
		if (q_line[m] == '$')
		{
			temp = ft_substr(q_line, s, m - s);
			result = ft_strjoin(result, temp);
			free(temp);
			s = m;
			while (q_line[m] || ft_strchr("' ''\t''$'", q_line[m] == 0))
				m++;
			temp = ft_substr(q_line, s, m - s);
			printf("temp: %s\n", temp);
			result = ft_strjoin(result, "---test---");
			free(temp);
		}
		if (q_line[m] != '$')
			m++;
	}
	temp = ft_substr(q_line, s, m - s);
	result = ft_strjoin(result, temp);
	free(temp);
}

int	main(void)
{
	char *in_d_quote = ft_strdup("1$HOME 2$LS_COLORS 3");
	printf("input: %s\n", in_d_quote);
	ft_d_roll(&in_d_quote);
	printf("result: %s\n", in_d_quote);
	return (0);
}