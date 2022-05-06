/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_simulating_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:37:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/05 09:15:18 by cemenjiv         ###   ########.fr       */
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

// Video is entitled "Simulating pipe operating in C"
// In this video, we are trying to reproduce the "ping -c google.com | grep round-trip " command 

int main (int argc, char *argv[])
{
	int fd[2];
	if (pipe(fd) == -1) // This create one unique pipe which will be associate with fd #3 (read) and fd # 4 (write)
		return 1;
	int pid1 = fork(); // We create a parent and a child process in here.  
	if (pid1 < 0) // If the fork command did not work, we exit program. 
		return 2;
	if (pid1 == 0) // Child process will execute the ping command first. 
	{
		dup2(fd[1], STDOUT_FILENO); // We take the "write" end of fd array, and copy its content in STDOUT
		close (fd[0]); // We close the  "read" end because we don't use it. 
		close (fd[1]); // We close this fd because "write" end has been duplicated to STDOUT already
		execlp("ping", "ping", "-c", "5", "google.com", NULL); // we will probably use execve instead
	}
	int pid2 = fork(); // Here we are in parent process , and we do another child. Therefore, there will be  1 parent in 2 child. 2 child are from same parent
	if (pid2 < 0)
		return 3;
	if (pid2 == 0) // We are in the child process 2 (grep command)
	{
		dup2(fd[0], STDIN_FILENO); // For grep command, we replace close STDIN and put the content of "read" end in STDIN
		close (fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "round-trip", NULL);
	}
	close(fd[0]); // we must close fd in parent process as well. 
	close(fd[1]); // the fd are duplicated in child process, we must alos close it in parent process
	waitpid(pid1, NULL, 0); // Validate what this waitpid is about
	waitpid(pid2, NULL, 0);
	return (0);	
}