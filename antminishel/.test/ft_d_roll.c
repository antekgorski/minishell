#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

// cc ft_d_roll.c -L ../libft -lft -g

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*costr;

	if (!s1 && !s2)
		return (NULL);
	costr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (costr == NULL)
		return (NULL);
	ft_strlcpy(costr, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(costr, (char *)s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (costr);
}

// void	ft_d_roll(char **in_d_quote)
// {
// 	char	*temp;
// 	char	*result;
// 	char	*q_line;
// 	int		s;
// 	int		m;
// 	int		flag;

// 	result = NULL;
// 	s = 0;
// 	m = 0;
// 	flag = 0;
// 	q_line = *in_d_quote;
// 	while (q_line[m])
// 	{
// 		if (q_line[m] == '$')
// 		{
// 			temp = ft_substr((const char*)q_line, (unsigned int)s, (size_t)(m
//						- s));
// 			result = ft_strjoin(result, temp);
// 			free(temp);
// 			s = m;
// 			while (q_line[m] && !ft_strchr("' ''\t''$'", q_line[m]))
// 				m++;
// 			temp = ft_substr(q_line, s, m - s);
// 			printf("temp: %s\n", temp);
// 			result = ft_strjoin(result, "---test---");
// 			free(temp);
// 		}
// 		if (q_line[m] != '$')
// 			m++;
// 	}
// 	temp = ft_substr(q_line, s, m - s);
// 	result = ft_strjoin(result, temp);
// 	free(temp);
// }

void	ft_d_roll(char **in_d_quote)
{
	static int	s;
	static int	m;
	static char		*temp;
	static char		*result;
	static char		*r_dolar;

	// result = NULL;
	// temp = NULL;
	// r_dolar = NULL;

	while ((*in_d_quote)[m])
	{
		if ((*in_d_quote)[m] == '$')
		{
			temp = ft_substr(*in_d_quote, s, m - s);
			result = ft_strjoin(result, temp);
			free(temp);
			s = m;
			while ((*in_d_quote)[m] && !ft_strchr("' ''\t''$'",
					(*in_d_quote)[m]))
				m++;
			temp = ft_substr(*in_d_quote, s, m - s);
			// r_dolar = ft_get_env(temp);
			r_dolar = ft_strdup("AAA");
			free(temp);
			result = ft_strjoin(result, r_dolar);
			free(r_dolar);
		}
		if ((*in_d_quote)[m] != '$')
			m++;
	}
	temp = ft_substr(*in_d_quote, s, m - s);
	result = ft_strjoin(result, temp);
	free(temp);
	free(*in_d_quote);
	in_d_quote = &result;
}

int	main(void)
{
	char *in_d_quote = ft_strdup("1$BB $BB 2$BB&BB");
	printf("input: %s\n", in_d_quote);
	ft_d_roll(&in_d_quote);
	printf("result: %s\n", in_d_quote);
	return (0);
}

		{
			if (line[t.start + 1] == '$')
				t.start += 2;
			else
				t.start++;
			t.end = t.start;
			while (line[t.end] && !ft_strchr("'$'' ''\t'", line[t.end]))
				t.end++;
			t.var_name = ft_substr(line, t.start, t.end - t.start);
			t.temp_env = ft_get_env(minishell->m_env, t.var_name);
			free(t.var_name);
			t.var_value = ft_strdup(t.temp_env);
			if (t.var_value)
			{
				t.temp = ft_strjoin(t.result, t.var_value);
				if (t.result)
					free(t.result);
				t.result = t.temp;
			}
			t.start = t.end;
		}