/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:19:56 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 11:42:47 by cemenjiv         ###   ########.fr       */
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

// Video called "Introduction to FIFOs"
// the myfifo1 file will not appear until you launch a.out and refresh files 
// - When you launch the program, you may notice it gets stuck. The reason being
// that the command open with FIFOs must wait until the other end (of the pipe) is opened.
// - You can also use "mkfifo" command directly in terminal Ex: "mkfifo myfifo2"

int main (int argc, char **argv)
{
	if (mkfifo("myfifo1", 0666) == -1) // Command to make fifos. For more info, "man fifo"
	{
		if (errno != EEXIST)
		{
			printf("Could not create FIFO file\n");
			return 1;
		}
	}
	printf("Opening ....\n");
	int fd = open("myfifo1", O_WRONLY);
	if (fd == -1)
	{
		return 3;
	}
	printf("Opened ....\n");
	int x = 'Z';
	if (write(fd, &x, sizeof(x)) == -1)
		return 2;
	printf("Opened ....\n");
	close (fd);
	printf("Closed ....\n");
	return (0);	
}