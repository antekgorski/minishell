#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	int pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0) // child
	{
		close(fd[0]);
		char str[200];
        printf("wtite somtfing:");
        fgets(str, 200, stdin);
		// if ((fgets(str, 200, STDIN_FILENO)) != NULL)
		// 	printf("readed str %s\n", str);
		// else
		// 	printf("reading error");
		int n = strlen(str) + 1;
		if (write(fd[1], &n, sizeof(n)) < 0)
			return (3);
		if (write(fd[1], str, sizeof(char) * n) < 0)
			return (4);
		close(fd[1]);
	}
	else // parent
	{
		close(fd[1]);
		int n;
		char str[200];
		if (read(fd[0], &n, sizeof(n)) < 0)
			return (5);
		if (read(fd[0], str, sizeof(char) * n) < 0)
			return (6);
        //str[n - 1] = '\0';
        printf("recived %s\n", str);
        close(fd[0]);
        wait(NULL);
	}
	return (0);
}
