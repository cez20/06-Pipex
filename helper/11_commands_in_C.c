/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_commands_in_C.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:19:17 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 12:37:06 by cemenjiv         ###   ########.fr       */
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

// Video is entitle "Executing commands in C"
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
		execlp("ping", "ping, "-c", "3", "google.com", NULL);
	}
	else //Parent process 
	{
		wait(NULL);
		printf("Success");
		printf("Some post processing goes here\n")
	}
	return (0);	
}