/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_communication1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:03:31 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 12:24:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> // Library in order to use mkfifo
#include <sys/wait.h> // Library in order to use mkfifo
#include <sys/errno.h> // Library needed for errno command below. 
#include <fcntl.h>
#include <time.h>

// Video called "How to use FIFO files to communicate between processes in C"
// This video shows how to create 2 programs. One that will generate numbers and the other that
// will read the numbers and sum them. 
// 1st program = fifo_communication.c 2nd program = fifo_communication1.c. Importance de creer un executable pour chaque

int main (int argc, char **argv)
{
	int arr[5];
	int fd = open("sum", O_RDONLY);
	if (fd == 1)
	{
		return 1;
	}
	int i;
	for (i = 0; i < 5; i++)
	{
		if (read(fd, &arr[i], sizeof(int)) == -1)
		{
			return 2;
		}
		printf("Received %d\n", arr[i]); // Receiving the numbers that are initially written in other program
	}
	close (fd);
	int sum = 0;
	for (i = 0; i < 5; i++)
		sum += arr[i];
	printf("Result is %d\n", sum); // Writing the sum following the reception of numbers
	return (0);	
}