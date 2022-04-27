/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_communication.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:15:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 08:52:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/errno.h> // Library needed for errno command below. 

// Video called "communication between process using pipes"
// 3:00 : Explanation of fd indepence. Fork allows child and parent to use same fd , but each fd is independent even though they have same number.
// 5:14 : Explanation of why 2 fd are needed when doing a pipe. Ex: fd[0] = read from, fd [1] = write to 

int main (int argc, char **argv)
{
	int fd[2]; // int array of 2. Essential this array contains 2 files descriptors: fd[0] fd[1]. They will contain text we can read from or write to
	if (pipe(fd) == -1) // if pipe, returns non-zero number or -1 it means there is an error. 
	{
		printf("An error occured with pipe");
		return 1; // if you return different numbers, it allows you to see clearly where your mistake is.
	}
	int id = fork (); // When fork is called, the fd are kind of copy over. If same fd is used with different process, each fd is indepedent even though they have same number.  
	if (id == -1)
	{
		printf("An error occured with fork()";
		return 2;
	}
	if (id == 0)
	{
		close (fd[0]); // We close this, because we never read inside this process. 
		int x;
		printf("Input a number:");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error occured with writing to the pipe");
			return 3;
		}
		close(fd[1]);
	}
	else
	{
		close (fd[1]); // Close the fd not used always before doing the operations. 
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1);
		{
			printf("An error occured with reading from the pipe");
			return 4;
		}
		close (fd[0]);
		printf("Got from child process number:  %d\n", y);
	}
	return (0);	
}