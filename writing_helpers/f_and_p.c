#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int argv, char *argc[])
{
	int arr[] = {1, 2, 3, 4, 1, 2}; // tworzenie tablicy
	int arrSize = sizeof(arr) / sizeof(int); // rozmiar tablicy
	int start;
	int end;
	int fd[2]; // deskryptor pliku
	int sum_from_child;
	int total_sum;
	// fd[0] - read
	// fd[1] - write
	if (pipe(fd) == -1) // tworzenie pipe
		return (1);
	int id = fork(); // tworzenie procesu potomnego
	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;
	int i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("sum of array is %d\n", sum);
	if (id == 0) // proces potomny
	{
		close(fd[0]); // zamyka deskryptor pliku dla odczytu
		write(fd[1], &sum, sizeof(int));	// zapisuje sume do deskryptora pliku
		close(fd[1]);	//	zamyka deskryptor pliku dla zapisu
	}
	else	// proces rodzica
	{
		close(fd[1]); // zamyka deskryptor pliku dla zapisu
		read(fd[0], &sum_from_child, sizeof(int));// czyta sume z deskryptora pliku
		close(fd[0]);// zamyka deskryptor pliku dla odczytu

		total_sum = sum + sum_from_child;// dodaje sume z procesu potomnego do sumy z procesu rodzica
		printf("total sum is %d\n", total_sum);
		wait(NULL);// czeka na zakonczenie procesu potomnego
	}
	return (0);
}