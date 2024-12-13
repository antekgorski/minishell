#include "minishell.h"

static int	quote_dcheck(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			j = i + 1;
			while (line[j] != '\"')
			{
				if (line[j] == '\0')
					return (1);
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

static int	quote_scheck(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			j = i + 1;
			while (line[j] != '\'')
			{
				if (line[j] == '\0')
					return (1);
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

void	check_quote(char *line)
{
	if (quote_scheck(line) == 1)
	{
		printf("Unmatched single quote. Please check your input.\n");
	}
	if (quote_dcheck(line) == 1)
	{
		printf("Unmatched duble quote. Please check your input.\n");
	}
	else
		return ;
	// quote handler
}
// printf("Error: Unmatched duble quote.\n");
// printf("Error: Unmatched single quote.\n");
