/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/15 17:42:02 by cemenjiv         ###   ########.fr       */
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

char	**split_path(char **env, char **path)
{
	int 	i;

	i = 0;
	while(env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			path = ft_split(&env[i][5], ':');
		i++;
	}
	return (path);
}

char	*get_cmd(char **path, char **cmd)
{
	char	*tmp;
	char	*command;

	while(*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(command, X_OK) != -1)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
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