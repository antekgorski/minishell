#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	n;
	int	id1;
	int	id2;

	id1 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("process fork:%i\n", getpid());
			printf("parent of this process:%i\n", getppid());
            printf("\n");
		}
		else
		{
			printf("process fork:%i\n", getpid());
			printf("parent of this process:%i\n", getppid());
             printf("\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf("process fork:%i\n", getpid());
			printf("parent of this process:%i\n", getppid());
             printf("\n");
		}
		else
		{
			printf("process fork:%i\n", getpid());
			printf("parent of this process:%i\n", getppid());
             printf("\n");
		}
	}
	while ((wait(NULL) != -1) || (errno != ECHILD))
	{
		printf("WAITED FOR CHILD FINISH\n");
	}
}
// n = 3;
//     printf("Child process fork:%i\n", id);
//     printf("Child process id pid %i\n", getpid());
//     printf("Child process id pid %i\n", getpid());
// n = 5;
// printf("Parent process fork:%i\n", id);
// printf("Parent process id pid %i\n", getpid());
// printf("Parent process id pid %i\n", getpid());
// usleep(1000);
// printf("Parent process\n");

// int i;
// while(n > 0)
// {
//     n--;
//     printf("%i\n", n);
//     fflush(stdout);
// }
// if(id != 0)
// {
//     printf("\n");
//     //wait(NULL);
// }
// printf("%i", n);
// printf("\n");