/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/15 17:53:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[], char *env[])
{
	char	**paths;
	char	**cmd;
	char	*cmd_path;

	paths = NULL;
	cmd = ft_split(argv[2], ' '); // This command could be put between "paths" and "command paths"
	if (argc != 5)
		return (msg(ERR_ARG));
	file_validation(argc, argv);
	input_redirection(argv);
	paths = split_path(env, paths);
	cmd_path = get_cmd(paths, cmd);
	printf("%s\n", cmd_path);
	
	
	//ELEMENTS TO REMEMBER TO FREE
	free_memory(paths); // free_memory function is used with double pointers. 
	free_memory(cmd);
	free(cmd_path);
	
	return (0);	
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err)); // fd == 2 because associated with STDERR. 
	exit(EXIT_FAILURE);
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
