#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void	signal_handlesigusr1(int signum)
{
	printf("remember \"tabliczka mnozenia\" allways!! \n");
}

int	main(int argc, char *agrv[])
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) // child
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else // parent
	{
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &signal_handlesigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		int x;
		printf("what is the result of 5 x 2?\n");
		scanf("%d", &x);
		if (x == 10)
			printf("Correct!\n");
		else
			printf("Wrong!\n");
		wait(NULL);
	}
	return (0);
}