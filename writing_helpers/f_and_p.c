#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argv, char *argc[])
{
	int arr[] = {1, 2, 3, 4, 1, 2};
	int arrSize = sizeof(arr) / sizeof(int);
	int start;
	int end;
	int fd[2];
	int sum_from_child;
	int total_sum;
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1)
		return (1);
	int id = fork();
	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;
	int i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("sum of array is %d\n", sum);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &sum_from_child, sizeof(int));
		close(fd[0]);

		total_sum = sum + sum_from_child;
		printf("total sum is %d\n", total_sum);
		wait(NULL);
	}
	return (0);
}