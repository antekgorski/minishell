#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	main(int argc, char *agrv[])
{
	int pid = fork();
	if (pid == -1)
		return (1);
    if(pid == 0)//child
    {
      while(1)
      {
          printf("child process\n");
          usleep(500000);
      }
    }
    else//parent
    {
        
        sleep(5);
        kill(pid, SIGKILL);//wywolanie sygnalu SIGKILL
        wait(NULL);
    }
    return (0);
}