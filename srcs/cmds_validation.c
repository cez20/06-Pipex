/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/15 16:34:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_redirection(char *argv[])
{
	int infile;

	infile = open(argv[1], O_RDONLY, 0644); 
	dup2(infile, STDIN_FILENO); 
	close (infile);
}

char	**split_path(char *env[])
{
	char 	**args;
	char	**args1;
	int 	i;

	args = NULL;
	args1 = NULL;
	i = 0;
	while(env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5)) // 
			args = ft_split(&env[i][5], ':'); // 1er malloc 
		i++;
	}
	args1 = malloc((i + 1) * sizeof(*args1));
	i = 0;
	while (args[i])
	{
		args1[i] = ft_strjoin(args[i], "/"); // 2e malloc
		i++;
	}
	args1[i] = 0;
	free_memory(args); // I free the args arguments, because stjoing create a new memory block
	return (args1);
}

char	*valid_cmd(char *argv[], char *args[], char **cmd1)
{
	char	*args1;
	char	*string;
	char	*valid_cmd1;
	int 	i;
	
	i = 0;
	while (args[i])
	{
		args1 = ft_strjoin(args[i], cmd1[0]); // Nouvel appel a strjoin
		if (access(args1, X_OK) != -1)
			valid_cmd1 = ft_strdup(args1); // I NEED to free this memory
		free(args1);
		i++;
	}
	if (!valid_cmd1) // Error handling when command it not found. 
	{
		string = ft_strjoin("bash: ", argv[2]);
		write(2, string, ft_strlen(string));
		write(2, ERR_CMD, ft_strlen(ERR_CMD)); // Hard coded, but needed to be changed
		exit (EXIT_FAILURE);
	}
	free_memory(args); // free le bloc de memoire
	return (valid_cmd1);
}

void	free_memory(char *args[])
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free (args);
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
	
//}