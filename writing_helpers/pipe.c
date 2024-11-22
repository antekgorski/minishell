#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int fd[2];
    // fd[0] - read
    // fd[1] - write
    if (pipe(fd) == -1)
    {
        printf("Error with opening pipe\n");
        return (1);
    }
    int id = fork();
    if(id ==0)
    {
        close(fd[0]);
        int x;
        printf("Imput number:");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("teaken from child proces %d", y);
    }

    return (0);
}