/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/14 23:02:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	split_path(char *argv[],char *env[])
{
	char 	**args;
	char	*cmd;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while(env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5)) // search for the word path
		{
			printf("You found the word PATH= !\n");	
			args = ft_split(&env[i][5], ':'); // Commence le split a l'addresse de env[i] + 5, soit 5 places plus loin
			while (args[j])
				printf("%s\n", args[j++]);
		}
		i++;
	}
	i = 0;
	printf("Voici les paths avec l'ajout du / a la fin :\n");
	while (args[i])
	{
		args[i] = ft_strjoin(args[i], "/"); // Valider s'il est pertinent de reprenre la meme variable args
		printf("%s\n", args[i++]);
	}
	cmd = strdup(argv[2]);
	printf("%s\n", cmd);
	i = 0;
	while (args[i])
	{
		args[i] = ft_strjoin(args[i], cmd);
		printf("%s\n", args[i++]);
	}
}

void	cmd_validation(int argc, char *argv[], char *env[])
{
	(void)argc;
	//int 	fd[2];
	int		infile;
	int		i;
	int		j;
	//char	line[1000]; // a enlever
	//pid_t 	pid; // why do we use pid_t

	i = 0;
	j = 0;
	infile = open(argv[1], O_RDONLY, 0644); // infile contient le file descriptor dans leqel le 1er fichier s'ouvrira. 
	dup2(infile, STDIN_FILENO); // infile is in fd #3 and we put its content in STDIN.
	//fgets(line, 1000, stdin); //function that allows to read 1st line of stdin and store in "line" file
	//puts(line); // prints outs the content of line and confirms that it has been put in stdin. 
	close (infile); // we close this fd as it is no longer needed because dup2 transfered its contents to STDIN
	split_path(argv, env);
}


// int main (int argc, char **argv, char *env[])
// {
// 	(void)argv;
// 	char	**args;
// 	char	**args1;
// 	char	**args2;
// 	int 	i;
// 	int		j;
// 	int		k;
// 	int 	y;
// 	int 	z;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	y = 0;
// 	z = 0;
// 	args = NULL;
// 	args1 = malloc(8 * sizeof(args1)); // malloc pour contenir les strjoin.
// 	args2 = malloc (sizeof(args2)); 
// 	if (argc != 5)
// 		write(1, "Invalid number of arguments!\n", 29);
// 	while(env[i])
// 	{
// 		if (strstr(env[i], "PATH=")) // search fo
// 		{
// 			printf("You found the word PATH= !\n");	
// 			args = ft_split(&env[i][5], ':'); // Commence le split a l'addresse de env[i] + 5, soit 5 places plus loin
// 			while (args[j])
// 				printf("%s\n", args[j++]);
// 			while (args[k])
// 			{
// 				args1[k] = ft_strjoin(args[k], "/"); // Il est necessaire de creer une nouvelle variable
// 				printf("%s\n", args1[k++]);
// 			}
// 			args1[k] = 0;
// 			while (y < 7)
// 			{
// 				args2[0] = ft_strjoin(args1[y], argv[1]); // join path with command "ls" or other
// 				if (access(args2[0], X_OK) != -1) // if no error code, then the path mixed with command was right one. 
// 					printf("Command was successfully executed\n");
// 				else
// 					printf("This is not the right path\n");
// 				free(args2[0]);	
// 				y++;	
// 			}
// 			free (args2); 
// 			break;
// 		}
// 		i++;
// 	}
// 	while (args[z] && args1[z])  // sections in order to free memory 
// 	{
// 		free(args[z]);
// 		free(args1[z]);
// 		z++;
// 	}
// 	free (args);
// 	free (args1);
// 	return (0);
// }



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