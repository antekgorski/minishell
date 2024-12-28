/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prutkows <prutkows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:54:52 by prutkows          #+#    #+#             */
/*   Updated: 2024/12/22 18:11:34 by prutkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// Funkcja łącząca dwa stringi i zwalniająca pamięć pierwszego
static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	joined_str = ft_strjoin(s1, s2);
	if (!joined_str)
		return (NULL);
	free(s1);
	return (joined_str);
}
// Funkcja wyszukująca zmienną PATH w środowisku i zwracająca jej wartość
static char	*get_path_variable(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_strdup(*envp + 5));
		envp++;
	}
	return (NULL);
}
// Funkcja konstruująca pełną ścieżkę do pliku na podstawie katalogu (token) i nazwy polecenia
static char	*construct_full_path(const char *token, const char *command)
{
	char	*full_path;
	size_t	len;

	len = ft_strlen(token) + ft_strlen(command) + 2;
	full_path = (char *)malloc(len);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, (char *)token, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, command, len);
	return (full_path);
}
// Funkcja wyszukująca wykonywalny plik w katalogach podanych w zmiennej PATH
static char	*find_executable(char *command, char **envp)
{
	char	*path;
	char	*token;
	char	*full_path;

	path = get_path_variable(envp);
	token = strtok(path, ":");
	while (token)
	{
		full_path = construct_full_path(token, command);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
// Funkcja zwalniająca pamięć zaalokowaną dla tablicy dwuwymiarowej
static void	ft_free_split(char ***split)
{
	int	i;

	if (!split || !*split)
		return ;
	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}
// Funkcja licząca liczbę zmiennych środowiskowych w liście
static int	count_env_variables(t_list *env)
{
	t_list	*current;
	int		count;

	count = 0;
	current = env;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
// Funkcja konwertująca listę zmiennych środowiskowych na tablicę odpowiednią dla execve
static char	**convert_env_to_envp(t_list *env, int count)
{
	t_list	*current;
	char	**envp;
	int		i;
	char	**env_vars;

	envp = malloc((count + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		env_vars = (char **)current->content;
		if (env_vars[1])
		{
			envp[i] = ft_strjoin(env_vars[0], "=");
			envp[i] = ft_strjoin_free(envp[i], env_vars[1]);
		}
		else
			envp[i] = ft_strdup(env_vars[0]);
		i++;
		current = current->next;
	}
	envp[i] = NULL;
	return (envp);
}
// Funkcja konwertująca listę zmiennych środowiskowych na tablicę dla execve
static char	**list_to_envp(t_list *env)
{
	int	count;

	count = count_env_variables(env);
	return (convert_env_to_envp(env, count));
}
// Funkcja wykonująca proces potomny, uruchamiająca polecenie zewnętrzne
static void	execute_child_process(char **args, t_minishell *minishell)
{
	char	*exec_path;
	char	**envp;

	envp = list_to_envp(minishell->m_env);
	if (!envp)
	{
		perror("envp");
		exit(EXIT_FAILURE);
	}
	exec_path = find_executable(args[0], envp);
	if (!exec_path)
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_split(&envp);
		exit(EXIT_FAILURE);
	}
	if (execve(exec_path, args, envp) == -1)
	{
		perror("execve");
		free(exec_path);
		ft_free_split(&envp);
		exit(EXIT_FAILURE);
	}
}
// Funkcja oczekująca na zakończenie procesu potomnego i zwracająca jego status
static int	wait_for_child_process(pid_t pid)
{
	int	status;

	while (1)
	{
		if (waitpid(pid, &status, WUNTRACED) == -1)
			return (EXIT_FAILURE);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
	}
	return (status);
}
// Funkcja wykonująca polecenie zewnętrzne w nowym procesie
int	execute_external(char **args, t_minishell *minishell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		execute_child_process(args, minishell);
	else
		status = wait_for_child_process(pid);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (status);
}

// int execute_tokens(char **args, t_minishell *minishell)
// {
// 		t_list *current;

//     current = minishell->token_list;
//     while (current)
//     {
//         t_token *token = (t_token *)current->content;
//         if (*token == CMD)
//         {
//             char **args = get_args_from_token(current);
//             if (!args)
//                 return (1);
//             if (e_bild(args, minishell) != 0)
	// Obsługa builtins lub external
//                 free_args(args);
//             else
//                 execute_external(args, minishell);
	// Wykonanie polecenia zewnętrznego
//             free_args(args);
//         }
//         else if (*token == PIPE)
//         {
//             // Obsługa potoków (pipe)
//             handle_pipe(minishell, current);
//         }
//         else if (*token == IREDIR || *token == OREDIR || *token == APPEND
	// || *token == HERDOC)
//         {
//             // Obsługa redirekcji
//             handle_redirection(minishell, current);
//         }
//         current = current->next;
//     }
//     return (0);
// }
