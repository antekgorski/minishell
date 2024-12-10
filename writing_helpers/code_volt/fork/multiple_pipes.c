#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int fd[3][2];
	int i;
	i = 0;
	while (i < 3)
	{
		if (pipe(fd[i++]) < 0)
			return (1);
	}

	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0) // child 1 proces
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int x;
		if (read(fd[0][0], &x, sizeof(int)) < 0)
			return (3);

		printf("child proces 1 read x=%d\n", x);
		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0)
			return (4);
		printf("child proces 1 write x=%d\n", x);

		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}
	int pid2 = fork();
	if (pid2 < 0)
		return (5);
	if (pid2 == 0) // child proces 2
	{
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		int x;
		if (read(fd[1][0], &x, sizeof(int)) < 0)
			return (6);
		printf("child proces 2 read x=%d\n", x);
		x += 5;
		if (write(fd[2][1], &x, sizeof(int)) < 0)
			return (7);
		printf("child proces 2 write x=%d\n", x);
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}
	// parent proces
	close(fd[0][0]);
	close(fd[1][1]);
	close(fd[1][0]);
	close(fd[2][1]);
	int x = 0;
	if (write(fd[0][1], &x, sizeof(int)) < 0)
		return (8);
	if (read(fd[2][0], &x, sizeof(int)) < 0)
		return (9);
	printf("result is:%d\n", x);
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

// child proces 1 read x=0
// child proces 1 write x=5
// child proces 2 read x=5
// child proces 2 write x=10
// result is:10