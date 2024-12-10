#include "../headers/minishell.h"

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
				{
					printf("Error: Unmatched duble quote.\n");
					return (1);
				}
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
				{
					printf("Error: Unmatched single quote.\n");
					return (1);
				}
				j++;
			}
			i = j + 1;
		}
		else
			i++;
	}
	return (0);
}

int	check_quote(char *line)
{
	if (quote_scheck(line) == 1 || quote_dcheck(line) == 1)
		return (1);
	else
		return (0);
}


