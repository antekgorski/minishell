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

	id1 = fork(); // tworzenie procesu potomnego
	id2 = fork();	// tworzenie procesu potomnego
	if (id1 == 0)// jesli id1 = 0 to proces potomny
{
		if (id2 == 0)// jesli id2 = 0 to proces potomny
		{
			printf("process fork:%i\n", getpid()); // wypisuje id procesu
			printf("parent of this process:%i\n", getppid());// wypisuje id rodzica
            printf("\n");
		}
		else// jesli id2 != 0 to proces rodzica
		
		{
			printf("process fork:%i\n", getpid());// wypisuje id procesu
			printf("parent of this process:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
	}
	else// jesli id1 != 0 to proces rodzica
	{
		if (id2 == 0)// jesli id2 = 0 to proces potomny
		{
			printf("process fork:%i\n", getpid());// wypisuje id procesu
			printf("parent of this process:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
		else
		{
			printf("process fork:%i\n", getpid());// wypisuje id procesu
			printf("parent of this process:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
	}
	while ((wait(NULL) != -1) || (errno != ECHILD))// czeka na zakonczenie procesu potomnego
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