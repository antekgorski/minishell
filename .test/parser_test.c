//put like executable function to parser.c
		ft_parser_test(minishell);
void	ft_parser_test(t_minishell *minishell)
{
	int	i;
	t_list	*temp;
	temp = minishell->token_list;

	i = 0;
	while (minishell->lexter_tab[i])
	{
		printf("%s\t%i\n", minishell->lexter_tab[i],
			*(int *)temp->content);
		i++;
		temp = temp->next;
	}
}