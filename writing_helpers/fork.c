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
	printf("Parent proces before fork, curent ID:(%d), parent ID:(%d)\n\n", getpid(), getppid());

	id1 = fork(); // tworzenie procesu potomnego
	id2 = fork();	// tworzenie procesu potomnego
	// printf("fork return to id1(%d)\n", id1);
	// printf("fork return to id2(%d)\n\n", id2);

	if (id1 == 0)// jesli id1 = 0 to proces potomny
{
		if (id2 == 0)// jesli id2 = 0 to proces potomny
		{
			printf("1-returned by fork id1:(%d) rerurned by fork id2:(%d), curent ID:(%d), parent ID:(%d)\n", id1, id2, getpid(), getppid());
			// printf("curent proces id:(%i)\n", getpid()); // wypisuje id procesu
			// printf("parent pid:%i\n", getppid());// wypisuje id rodzica
            printf("\n");
		}
		else// jesli id2 != 0 to proces rodzica
		
		{
			printf("2-returned by fork id1:(%d) rerurned by fork id2:(%d), curent ID:(%d), parent ID:(%d)\n", id1, id2, getpid(), getppid());
			// printf("curent proces id:(%i)\n", getpid());// wypisuje id procesu
			// printf("parent pid:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
	}
	else// jesli id1 != 0 to proces rodzica
	{
		if (id2 == 0)// jesli id2 = 0 to proces potomny
		{
			printf("3-returned by fork id1:(%d) rerurned by fork id2:(%d), curent ID:(%d), parent ID:(%d)\n", id1, id2, getpid(), getppid());
			// printf("curent proces id:(%i)\n", getpid());// wypisuje id procesu
			// printf("parent pid:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
		else
		{
			printf("4-returned by fork id1:(%d) rerurned by fork id2:(%d), curent ID:(%d), parent ID:(%d)\n", id1, id2, getpid(), getppid());
			// printf("curent proces id:(%i)\n", getpid());// wypisuje id procesu
			// printf("parent pid:%i\n", getppid());// wypisuje id rodzica
             printf("\n");
		}
	}
	while ((wait(NULL) != -1) || (errno != ECHILD))// czeka na zakonczenie procesu potomnego
	{
		printf("WAITED FOR CHILD FINISH\n");
	}
}
// Proces Rodzica
// ├── Child1 (id1 = 0)
// │   └── Child3 (id2 = 0)
// └── Child2 (id2 = 0)

// P
// ├── fork1
// │   ├── fork2
// │   │   └── fork3
// │   └── fork3
// ├── fork2
// │   └── fork3
// └── fork3

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