/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_exit_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:42:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 12:58:56 by cemenjiv         ###   ########.fr       */
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

// Video is entitle "Getting exit status in C"
// With exec function, eveything is taken and executed. Thefore, once the exec function is over, verything is over.
// The commands coded after the exec will not execute.
// exec never to be done in parent process. 

int main (int argc, char *argv[])
{
	int pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0) // the execlp command replace the child. Thefore anything after this eec command will not show.
	{
		int err = execlp("ping", "ping", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute");
			return 0;
		}
	}
	else //Parent process 
	{
		int wstatus;
		wait(&wstatus); // wait takes a pointer 
		if (WIFEXITED(wstatus)) // Macro WIFEXITED that takes an int 
		{
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Success\n");
			else
				printf("Failure\n");
		}
		printf("Some post processing goes here\n");
	}
	return (0);	
}