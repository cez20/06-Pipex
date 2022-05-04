/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 07:25:15 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_creation(char **argv)
{
	int fd[2];
	int fds;
	int i;
	pid_t pid;
	
	i = 2;
	fds = open(argv[1], O_RDONLY);
	if (fds == -1)
	{
		printf("First argument is not an input\n");
		exit (EXIT_FAILURE);
	}
	printf("First argument is a valid input. Please continue!\n");
	close (fds); // Close this argv, because it is lo longer needed as it was for validation
	if (pipe(fd) == -1) // This creates a pipe inside 
		exit(EXIT_FAILURE);  // Est-ce que (EXIT_FAILURE) est la bonne commande 
	printf("The file descriptor in fds[0] is : %d\n", fd[0]); // fd for read
	printf("The file descriptor in fds[1] is : %d\n", fd[1]); // fd for write. 
	pid = fork(); // Child process is created and duplicate memory of parent process 
	if (pid == -1)
		exit(EXIT_FAILURE); // do I need to put perror or strerror here ? 
	if (pid == 0) // if pid == 0. This is the child process 
	{
		dup2(fd[0], STDIN_FILENO);  //STDIN is closed in child process and cut its link with keyboard. Fd[0] give content to STDIN
		close(fd[0]); // Close fd[0] as it is no longer needed. 
		close (fd[1]); // Write file descriptor is not used in child 
	}
	
}