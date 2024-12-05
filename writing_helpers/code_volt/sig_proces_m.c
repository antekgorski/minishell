#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int	main(int argc, char *agrv[])
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0) // child
	{
		while (1)
		{
			printf("child working...\n");
			usleep(500000);
		}
	}
	else // parent
	{
	kill(pid, SIGSTOP);// stop the child
	int time;
	do{
		printf("enter the time to execution:\n");
		scanf("%d", &time);
		if(time > 0)
			{
				kill(pid, SIGCONT);// continue the child
				sleep(time);
				kill(pid, SIGSTOP);// stop the child

			}
	} while(time > 0);

	sleep(1);
	kill(pid, SIGCONT);// continue the child
    sleep(3);
    kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
//fg coment send signal SIGCONT to the child process to continue
//bg coment send signal SIGSTOP to the child process to stop