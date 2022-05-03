/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/03 15:56:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_creation(char **argv)
{
	(void)argv;
	int fds[2];
	int pid;
	int i;
	
	i = 2;
	if (pipe(fds) == -1)
		exit(EXIT_FAILURE);  // Est-ce qu'il s'agit de la bonne commande a ce moment precis
	printf("The file descriptor in fds[0] is : %d\n", fds[0]); // Validate what is file descriptor number associated with READ fd[0]
	printf("The file descriptor in fds[1] is : %d\n", fds[1]); // Validate what is file descriptor number associated with WRITE fd[1] -> 
	pid = fork(); // Child process is created and duplicate memory of parent process 
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0) // if pid == 0. This is the child process 
	{
		dup2(fds[0], STDIN_FILENO);  //STDIN is closed in child process and cut its link with keyboard. Fd[0] give content to STDIN
		close(fds[0]); // Close fd[0] as it is no longer needed. 
		close (fds[1]); // Write file descriptor is not used in child 
		//execvp(argv[2], &argv[i]);
	}
	// else
	// {
		
	// }
}