//put like executable function to parser.c
void	ft_parser_test(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->lexter_tab[i])
	{
		printf("%s\t%i\n", minishell->lexter_tab[i], *(int *)minishell->token_list->content);
		i++;
		minishell->token_list = minishell->token_list->next;
	}
}