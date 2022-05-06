/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_wait_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:28:55 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/05 14:51:44 by cemenjiv         ###   ########.fr       */
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

// Video is entitled "What is waitpid"
// waitpid as opposed to wait() that waits for whatever child process to finish execution.
// it will wait for a specific child process to finish.  


int main (int argc, char *argv[])
{
	int pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error creating process");
		return 1;
	}
	if (pid1 == 0) // First child process 
	{
		sleep(4);
		printf("Finish executiong of %d\n", getpid());
		return 0;
	}
	int pid2= fork();
	if (pid2 == -1)
	{
		printf("Error creating process");
		return 2;
	}
	if (pid2 == 0)
	{
		sleep(1);
		printf("Finish executiong of %d\n", getpid());
		return 0;
	}
	
	int pid1_res = waitpid(pid1, NULL, 0); // This is the sleep(1) pid
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, 0); // This is the sleep (4) pid
	printf("Waited for %d\n", pid2_res);
}