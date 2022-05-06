/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_multiple_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:52:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/05 15:58:19 by cemenjiv         ###   ########.fr       */
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
#include <time.h> // necessary for srand(time(NULL) command 

// Video is entitled "Working with multiple pipes "


int main (int argc, char *argv[])
{
	int fd[3][2]; // an 2d array. Each fd will contrain 2fd . Ex: fd[0][0] fd[0][1] fd[0][2]
	int i;
	for (i = 0; i < 3; i++) // Loop that calls pipe 3 times. 
	{
		if (pipe(fd[i]) < 0) // Error handling
			return 1; 
	}	
	int pid1 = fork();
	if (pid1 < 0) // If the fork does not work correctly we should close all other pipes. 
		return 2;
	if (pid1 == 0) //Child process 
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int x;
		if (read(fd[0][0], &x, sizeof(int)) < 0)
			return 3;
		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) < 0)
			return 4;
		close (fd[0][0]);
		close (fd[1][1]);
		return (0);	
	}
	
	int pid2 = fork();
	if (pid2 < 0) // If the fork does not work correctly we should close all other pipes. 
		return 5;
	if (pid2 == 0) //Child process 
	{
		close(fd[0][1]);
		close(fd[0][0]);
		close(fd[1][1]);
		close(fd[2][0]);
		int x;
		if (read(fd[1][0], &x, sizeof(int)) < 0)
			return 6;
		x += 5;
		if (write(fd[2][1], &x, sizeof(int)) < 0)
			return 7;
		close (fd[1][0]);
		close (fd[2][1]);
		return (0);	
	}
	// We are here in parent process;
	close (fd[0][0]);
	close (fd[1][0]);
	close (fd[1][1]);
	close (fd[2][1]);
	int x = 0;
	if (write(fd[0][1], &x, sizeof(int)) < 0)
		return 8;
	if (read(fd[2][0], &x, sizeof(int)) < 0)
			return 9;
	printf("Result is %d\n", x);
	close (fd[0][1]);
	close (fd[2][0]);
	return(0);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}