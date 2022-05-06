/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_output_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:11:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/05 08:36:42 by cemenjiv         ###   ########.fr       */
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

// Video is entitle "Redirecting standard output in C"
// This video did not seem important for the pipex project 

int main (int argc, char *argv[])
{
	
	int pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0) // child process
	{
		int file = open ("Output", O_WRONLY | O_CREAT, 0777);
		if (file == 1)
			return 2; // there is mistake
		
	} 
	
	return (0);	
}