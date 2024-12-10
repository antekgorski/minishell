/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:09:54 by agorski           #+#    #+#             */
/*   Updated: 2024/11/24 14:29:13 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errno.h"
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "unistd.h"

int	main(int argc, char *argv[])
{
	if (mkfifo("myfifo1", 0777) == -1) // tworzy fifo
	{
		if (errno != EEXIST) // jesli fifo juz istnieje to errno = EEXIST
		{
			printf("Error creating fifo\n");
			return (1);
		}
	}
	int fd;
	printf("opening...\n");
	fd = open("myfifo1", O_WRONLY); // otwiera fifo dla zapisu
	printf("opened\n");
	int x;
	x = 97;
	if (write(fd, &x, sizeof(x)) == -1) // zapisuje do fifo
	{
		printf("Error writing to fifo\n");
		return (1);
	}
	printf("written\n");
	close(fd); // zamyka fifo
	printf("closed\n");
	unlink("myfifo1"); // usuwa fifo
	printf("unlinked\n");
	return (0);
}