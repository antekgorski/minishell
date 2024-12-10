#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		return (1);
	printf("fd nt:%d%d", fd[0], fd[1]);
	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0) // child proces 1 ping
	{
		dup2(fd[1], STDOUT_FILENO); // przypisuje fd[1] do stdout, i np execlp bedzie wysylal do fd[1]0 - STDIN, 1 - fd[1] 2 - STDERR,
		close(fd[0]);// zamykamy bo nie uzywamy.
		close(fd[1]);// zamykamy zebu nic innego nie wplywalo a tylko stdout
		execlp("ping", "ping", "-c", "5", "wp.pl", NULL);
	}
	int pid2 = fork();
	if (pid2 < 0)
		return (3);
    if (pid2 == 0)// child proces 2 (greep)
    {
        dup2(fd[0], STDIN_FILENO);//stdin bedzie teraz dopiety do fd[0] // 0 - fd[0], 1 - STDUOT 2 - STDERR, 3 - fd[0], 4- fd[1]
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "rtt", NULL);
    }
    //In C, when creating a pipe using the pipe() system call, 
    //both the parent and child processes inherit duplicate file descriptors for the read and write ends of the pipe.
    //This means each process has two file descriptors: p[0] for reading and p[1] for writing.
    close(fd[0]);
    close(fd[1]);
	waitpid(pid1, NULL, 0);// czeka na zakonczenie procesu potomnego pid1 NULL-nieinteresuje status zakonczenia 0-dziala w trybie blokujacym.
	waitpid(pid2, NULL, 0);
    return (0);
}

// +-------------------+
// |   Proces Rodzica  |
// +-------------------+
//         |
//         | fork() -> Child 1 ("ping")
//         |
//         | fork() -> Child 2 ("grep")
//         |
// +---------------+           +---------------+
// |  Child 1      |           |  Child 2      |
// |  ("ping")     |           |  ("grep")     |
// +---------------+           +---------------+
//         |                           ^
//         |                           |
//         +--------- Pipe ------------+
//         | (fd[1] -> STDOUT)          | (STDIN <- fd[0])


// Proces Rodzica
// ├── Otwarty fd[0] (Read End) - ZAMKNIĘTY
// ├── Otwarty fd[1] (Write End) - ZAMKNIĘTY
// ├── Child1 (ping)
// │   ├── fd[0] - ZAMKNIĘTY
// │   ├── fd[1] - ZAMKNIĘTY (przekierowane do STDOUT)
// │   └── exec("ping")
// └── Child2 (grep)
//     ├── fd[0] - Przekierowane do STDIN
//     ├── fd[1] - ZAMKNIĘTY
//     └── exec("grep")