/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_communication.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 12:30:21 by cemenjiv         ###   ########.fr       */
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


int main (int argc, char **argv)
{
	int arr[5];
	srand(time(NULL));
	int	i;
	for (i = 0; i < 5; i++)
	{
		arr[i] = rand() % 100;
		printf("Wrote %d\n", arr[i]);
	}
	int fd = open("sum", O_WRONLY);
	if (fd == -1)
	{
		return 1;
	}
	// for (i = 0; i < 5; i++)
	// {
	// 	if (write(fd, &arr[i], sizeof(int)) == -1)
	// 	{
	// 		return 2;
	// 	}
	// 	printf("Wrote %d\n", arr[i]);
	// }
	if (write(fd, arr, sizeof(int) * 5) == -1)
		return 2;
	close(fd);
	return (0);	
}