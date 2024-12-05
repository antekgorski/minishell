#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// 5 => 5 * 4 = 20 => 20
int	main(int atgc, char *argv[])
{
	int fd1[2]; // C => P
	int fd2[2]; // P => C
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd1) == -1 || pipe(fd2) == -1)
		return (1);
	int pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0) // we are in child process
	{
		close(fd2[1]);
		close(fd1[0]);
		int x;
		if (read(fd2[0], &x, sizeof(x)) == -1)
			return (3);
		printf("recived %d\n", x);
		close(fd2[0]);
		x *= 4;

		if (write(fd1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("wrote %d\n", x);
		close(fd1[1]);
	}
	else // we are in parent process
	{
		close(fd2[0]); // Zamykamy nieużywany koniec odczytu pipe'a fd2
		close(fd1[1]); // Zamykamy nieużywany koniec zapisu pipe'a fd1
		srand(time(NULL));
		int x = rand() % 10;
		if (write(fd2[1], &x, sizeof(x)) == -1)
			return (5);
		printf("wrote %d\n", x);
		close(fd2[1]);
		if (read(fd1[0], &x, sizeof(x)))
			return (6);
		printf("result is: %d\n", x);
		close(fd1[0]);
		wait(NULL); // wait for child process to finish
	}
	return (0);
}