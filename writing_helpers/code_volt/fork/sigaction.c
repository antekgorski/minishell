#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

void signal_handler(int signum)
{
    printf("Don`t do that!!\n");
}

int main(int argc, char *agrv[])
{
    struct sigaction sa;
    sa.sa_handler = &signal_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);

    int x;
    printf("Enter the number for sum of multiple 5 times: ");
    scanf("%d", &x);
    printf("The sum of multiple 5 times is: %d\n", x * 5);
    return (0);
}