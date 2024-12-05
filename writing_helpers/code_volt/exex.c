#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	pid;
	int	error;
	int	wstatus;
	int	file;

	pid = fork();
	if (pid == -1)
	{
		printf("error fork create!\n");
		return (1);
	}
	if (pid == 0) // child
	{
		int fd1;
        // FILE DESCRIPTORS 0 - STDIN, 1 - STDOUT, 2 - STDERR
        fd1 = open("pingresult.txt", O_WRONLY | O_CREAT, 0777);
		if (fd1 == -1)
			return (2);
        printf("the file descriptor is: %d\n", fd1);
        //int fd2;
        // 0 - STDIN, 1 - STDOUT, 2 - STDERR, 3 - fd1(pingresult.txt)
        //fd2 = dup(STDOUT_FILENO);// 0 - STDIN, 1 - STDOUT, 2 - STDERR 3 - fd1(pingresult.txt), 4 - STDOUT(fd2)
        //fd2 = dup(fd1);// 0 - STDIN, 1 - STDOUT, 2 - STDERR 3 - fd1(pingresult.txt), 4 - fd2(fd1)
        /*fd2 = */dup2(fd1, STDOUT_FILENO);// 0 - STDIN, 1 - fd1 2 - STDERR, 3 - fd1(pingresult.txt)
        //printf("the duplication of file descriptor is: %d\n", fd2);
        close(fd1);

		error = execlp("ping", "ping", "-c", "1", "wp.pl", NULL);
		if (error == -1)
		{
			printf("Program can`t be executed!\n");
			return (1);
		}
	}
	else // parent
	{
		wait(&wstatus);
			// czeka na zakonczenie procesu potomnego i zwraca status do zmiennej wstatus
		if (WIFEXITED(wstatus))
		{
			int statuscode = WEXITSTATUS(wstatus); // zwraca kod wyjscia procesu
			if (statuscode == 0)                   // jesli 0 to sukces
				printf("succes!\n");
			else // jesli inny to blad
				printf("error!\n");
		}
	}
	return (0);
}
// WIFEXITED(status): Sprawdza, czy proces zakończył się normalnie.
// WEXITSTATUS(status): Zwraca kod wyjścia procesu.
// WIFSIGNALED(status): Sprawdza, czy proces został zakończony przez sygnał.
// WTERMSIG(status): Zwraca numer sygnału, który zakończył proces.
// WIFSTOPPED(status): Sprawdza, czy proces został zatrzymany przez sygnał.
// WSTOPSIG(status): Zwraca numer sygnału, który zatrzymał proces.
// WIFCONTINUED(status): Sprawdza, czy proces został wznowiony po zatrzymaniu.

// execlp("ping", "ping", "wp.pl", NULL);//env wyswietla environment variables
// perror("execl");                       //czyli zmienne srodowiskowe
// return (0);