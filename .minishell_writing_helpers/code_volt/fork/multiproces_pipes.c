#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define CHILD_NUM 100

int	main(int argc, char *agrv[])
{
	int pids[CHILD_NUM];
	int fd[CHILD_NUM + 1][2];
	int i;
	i = 0;
	while ((CHILD_NUM + 1) > i)
	{
		if (pipe(fd[i]) == -1)
		{
			printf("creating pipes error\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (CHILD_NUM > i)
	{
		pids[i] = fork();
		if (pids[i] == -1)
		{
			printf("Creating process error!\n");
			return (2);
		}
		if (pids[i] == 0)
		{
			// we are in child proces
			int j;
			j = 0; // j -ktury pipe, i -ktury proces child
			while (j < CHILD_NUM + 1)
			{
				if (i != j)
					close(fd[j][0]);
				// nie zamykamy pipe do czytania z procesu poprzedniego
				if (i + 1 != j)
					close(fd[j][1]);
				// nie zamykamy pipe dla pisania do nastepnego procesu
				j++;
			}
			int x;
			if (read(fd[i][0], &x, sizeof(int)) == -1)
			{
				printf("reading error in proces:(%d)", getpid());
				return (3);
			}
			printf("child proces (%d) got %d\n", i + 1, x);
			// printf("Proces potomny %d o PID %d down\n", i, getpid());
			x++;
			if (write(fd[i + 1][1], &x, sizeof(int)) == -1)
			{
				printf("writeng error in proces:(%d)", getpid());
				return (4);
			}
			printf("child proces (%d) send %d\n", i + 1, x);
			close(fd[i][0]);
			close(fd[i + 1][1]);
			return (0);
		}
		i++;
	}
	// main proces runs
	int y = 5;
	printf("Main proces send: %d\n", y);
	if (write(fd[0][1], &y, sizeof(int)) == -1)
	{
		printf("writeng error in proces:(%d)", getpid());
		return (5);
	}
	if (read(fd[CHILD_NUM][0], &y, sizeof(int)) == -1)
	{
		printf("reading error in proces:(%d)", getpid());
		return (6);
	}
	printf("Mein proces got final result: %d", y);
	i = 0;
	close(id[0][1]);
	close(fd[CHILD_NUM][0]);
	while (CHILD_NUM > i)
	{
		wait(NULL);
		i++;
	}
	return (0);
}