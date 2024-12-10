#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int pid1 = fork();
	if (pid1 < 0)
	{
		printf("error creating proces 1");
		return (1);
	}
	if (pid1 == 0) // child  proces 1
	{
		sleep(4);
		printf("finished execiusion proses (%d)\n", getpid());
		return (0);
	}
	int pid2 = fork();
	if (pid2 < 0)
	{
		printf("error creating proces 2");
		return (1);
	}
	if (pid2 == 0) // child proces 2
	{
		sleep(1);
		printf("finished execiusion proses (%d)\n", getpid());
		return (0);
	}

	//int pid1_res = wait(NULL);
    int pid1_res = waitpid(pid1, NULL, 0);
    printf("waited for:%d\n", pid1_res);
	//int pid2_res = wait(NULL);
    int pid2_res = waitpid(pid2, NULL, 0);
    printf("waited for:%d\n", pid2_res);
	return (0);
}