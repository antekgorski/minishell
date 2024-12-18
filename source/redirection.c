#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef enum e_token
{
	DQUOTE,  // "
	SQUOTE,  // '
	PIPE,    // |
	IREDIR,  // <
	OREDIR,  // >
	APPEND,  // >>
	HERDOC,  // <<
	CMD,     // command
	TO_PARSE // to parse
}					t_token;
typedef struct s_redirection
{
	int type;       // np >, >>
	char *filename; // ścieżka do pliku lub zawartości (dla heredoc)
	int				fd;
}					t_redirection;

typedef struct s_cmd
{
	char			**args;
	t_redirection	*redir;
	int				redir_count;
	struct s_cmd	*next;
}					t_cmd;

void	handle_redirections(t_cmd *cmd)
{
	int				i;
	t_redirection	*re;
	int				fd;

	i = 0;
	while (i < cmd->redir_count)
	{
		re = &cmd->redir[i];
		i++;
		if (re->type == OREDIR)
			fd = open(re->filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (re->type == APPEND)
			fd = open(re->filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (re->type == IREDIR)
			fd = open(re->filename, O_RDONLY);
		else if (re->type == HERDOC)
		{
			// fd = create_heredoc(re->filename); // Funkcja do heredoc
		}
		if (fd < 0)
		{
			// error_handler();
		}
		if (dup2(fd, re->fd) < 0)
		{
			// error_handler();
		}
		close(fd);
	}
}
// Funkcja pomocnicza do wyczyszczenia redirekcji
void	reset_stdout(void)
{
	dup2(STDOUT_FILENO, 1); // Przywrócenie standardowego wyjścia
}
int	create_heredoc(char *filename)
{
	int	fd;

	// Symulacja heredoc - zapisujemy zawartość do pliku tymczasowego
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	write(fd, "heredoc content\n", 16);
	close(fd);
	return (open(filename, O_RDONLY));
}
// Funkcja testowa
void	test_redirections(void)
{
	t_redirection	redir1;
	t_cmd			cmd1;
	t_redirection	redir2;
	t_cmd			cmd2;
	t_redirection	redir3;
	t_cmd			cmd3;
	int				fd;
	char			buffer[256];
	t_redirection	redir4;
	t_cmd			cmd4;

	printf("Running redirection tests...\n");
	// Test 1: Przekierowanie wyjścia do pliku
	redir1.type = OREDIR;
	redir1.filename = "test_output.txt";
	redir1.fd = STDOUT_FILENO;
	cmd1.args = NULL;
	cmd1.redir = &redir1;
	cmd1.redir_count = 1;
	cmd1.next = NULL;
	handle_redirections(&cmd1);
	printf("This should be written to 'test_output.txt'\n");
	reset_stdout(); // Przywróć stdout
	// Test 2: Dopisanie do pliku
	redir2.type = APPEND;
	redir2.filename = "test_output.txt";
	redir2.fd = STDOUT_FILENO;
	cmd2.args = NULL;
	cmd2.redir = &redir2;
	cmd2.redir_count = 1;
	cmd2.next = NULL;
	handle_redirections(&cmd2);
	printf("This should be appended to 'test_output.txt'\n");
	reset_stdout(); // Przywróć stdout
	// Test 3: Przekierowanie wejścia z pliku
	redir3.type = IREDIR;
	redir3.filename = "test_input.txt";
	redir3.fd = STDIN_FILENO;
	cmd3.args = NULL;
	cmd3.redir = &redir3;
	cmd3.redir_count = 1;
	cmd3.next = NULL;
	// Tworzymy testowy plik wejściowy
	fd = open("test_input.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "input data\n", 11);
	close(fd);
	handle_redirections(&cmd3);
	read(STDIN_FILENO, buffer, 255);
	printf("Read from redirected stdin: %s", buffer);
	// Test 4: Heredoc
	redir4.type = HERDOC;
	redir4.filename = "heredoc_test.txt";
	redir4.fd = STDIN_FILENO;
	cmd4.args = NULL;
	cmd4.redir = &redir4;
	cmd4.redir_count = 1;
	cmd4.next = NULL;
	handle_redirections(&cmd4);
	read(STDIN_FILENO, buffer, 255);
	printf("Read from heredoc: %s", buffer);
	printf("All tests completed.\n");
}

int	main(void)
{
	test_redirections();
	return (0);
}