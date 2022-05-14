/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/14 15:09:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_validation(int argc, char *argv[], char *env[])
{
	int 	fd[2];
	int		read_data;
	pid_t 	pid; // why do we use pid_t

	if (pipe(fd) == -1) // This creates a pipe inside 
		exit(EXIT_FAILURE);  // Est-ce que (EXIT_FAILURE) est la bonne commande 
	printf("The file descriptor in fds[0] is : %d\n", fd[0]); // fd for read
	printf("The file descriptor in fds[1] is : %d\n", fd[1]); // fd for write. 
	pid = fork(); // Child process is created and duplicate memory of parent process 
	if (pid == -1)
		exit(EXIT_FAILURE); 
	if (pid == 0) // if pid == 0. This is the child process 
	{
		read_data = read(argv[argc - 1], &read_data, sizeof(int));
		printf ("%s\n", read_data);
		//dup2(fd[0], STDIN_FILENO);  //STDIN is closed in child process and cut its link with keyboard. Fd[0] give content to STDIN
		//close(fd[0]); // Close fd[0] as it is no longer needed. 
		//close (fd[1]); // Write file descriptor is not used in child 
	}
	
		
	}
	
}

// void	pipe_creation(char **argv)
// {
// 	int 	fd[2];
// 	char 	*string;
// 	char	cmd[];
// 	char	*argVec[];
// 	char	*envVec[];
// 	pid_t 	pid;
// 	int 	i;
	
// 	i = 2;
// 	char	*argVec[] = {NULL};
// 	char	*envVec[] = {NULL};
// 	cmd = "ls";
// 	if (access(argv[1], F_OK) == -1)
// 	{
// 		string = ft_strjoin("bash: ", argv[1]);
// 		perror(string);
// 		exit (EXIT_FAILURE);
// 	}
// 	printf("Start of the execve call %s: \n", cmd);
// 	printf("===========================================\n");
// 	if (execve(cmd, argVec, envVec) == -1)
// 		perror("Could not execute");
// 	printf("Oops, something went wrong");
// 	return (0);
	
	
	
	
	
	
	// if (pipe(fd) == -1) // This creates a pipe inside 
	// 	exit(EXIT_FAILURE);  // Est-ce que (EXIT_FAILURE) est la bonne commande 
	// printf("The file descriptor in fds[0] is : %d\n", fd[0]); // fd for read
	// printf("The file descriptor in fds[1] is : %d\n", fd[1]); // fd for write. 
	// pid = fork(); // Child process is created and duplicate memory of parent process 
	// if (pid == -1)
	// 	exit(EXIT_FAILURE); // do I need to put perror or strerror here ? 
	// if (pid == 0) // if pid == 0. This is the child process 
	// {
	// 	dup2(fd[0], STDIN_FILENO);  //STDIN is closed in child process and cut its link with keyboard. Fd[0] give content to STDIN
	// 	close(fd[0]); // Close fd[0] as it is no longer needed. 
	// 	close (fd[1]); // Write file descriptor is not used in child 
	// }
	
}