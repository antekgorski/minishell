#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *agrv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		return (2);
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) // child
	{
		close(fd[0]);
		srand(time(NULL));
		// int *arr = (int *)malloc(sizeof(int) * 10);
		int arr[10];
		int i = 0;
		while (i < 10)
		{
			arr[i] = rand() % 10;
            printf("%d ", arr[i]);
			i++;
		}
        printf("\n");
		
		write(fd[1], arr, sizeof(int) * 10);
		close(fd[1]);
	}
	else // parent
	{
		close(fd[1]);
		int arr[10];
		read(fd[0], arr, sizeof(int) * 10);
        int i = 0;
        int sum = 0;
        while(i < 10)
        {
            sum += arr[i++];
        }
        printf("sum od arr:%d\n", sum);
		close(fd[0]);
		wait(NULL);
	}
}