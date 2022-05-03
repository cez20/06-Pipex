/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_way_com.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:31:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/30 18:44:50 by cemenjiv         ###   ########.fr       */
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

// Video is entitled "Two way communication between processes (using pipes) in C"



int main (int argc, char **argv)
{
	int p1[2];
	if (pipe(p1) == -1)
		return 1;
	int pid = fork();
	if (pid == -1)
		return 2;
	if (pid == 0) // We are in the child process
	{
		int x;
		if (read(p1[0], &x, sizeof(x)) == -1)
			return 3;
		printf("Received %d\n", x);	
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return 4;
		printf("Wrote %d\n", x);	
	}
	else // Parent process
	{
		srand(time(NULL));
		int y = rand() % 10;
		if (write(p1[1], &y, sizeof(y)) == -1)
			return 5;
		printf("Wrote %d\n", y);
		if (read (p1[0], &y, sizeof(y)) == -1)
			printf("Result is %d\n", y);
		wait(NULL);
	}
	close (p1[0]);
	close (p1[1]);
	return (0);	
}
