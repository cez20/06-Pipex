/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/18 17:09:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	*pipex;

	if (argc != 5)
		return (msg(ERR_ARG));
	pipex = initialize_pipex();
	pipex->infile = open_infile(argv);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	pipex->paths = split_path(env);
	create_commands(pipex, argv);
	pipex->path_exe1 = merge_paths_commands(pipex);
	pipex->path_exe2 = merge_paths_commands1(pipex);
	create_pipe(pipex, env);
	free_memory(pipex->paths);
	free_memory(pipex->cmd1);
	free_memory(pipex->cmd2);
	free(pipex->path_exe1);
	free(pipex->path_exe2);
	free(pipex);
	return (0);
}

t_pipex	*initialize_pipex() // Est-ce que je dois faire pointer les pointers ici-bas a NULL?
{
	t_pipex	*pipex;

	pipex =	malloc(sizeof(pipex));
	pipex->paths = malloc(sizeof(pipex->paths));
	pipex->cmd1 = malloc(sizeof(pipex->cmd1));
	pipex->cmd2 = malloc(sizeof(pipex->cmd2));
	pipex->path_exe1 = malloc (sizeof(pipex->path_exe1));
	pipex->path_exe2 = malloc (sizeof(pipex->path_exe2));
	return	(pipex);
}

void	free_memory(char *args[])
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free (args);
}


//ELEMENTS TO REMEMBER TO FREE
	//free_memory(pipex->paths); // free_memory function is used with double pointers. 
	//free_memory(cmd1);
	//free_memory(cmd2);
	//free(cmd_path1);
	//free(cmd_path2);

	// printf("%s\n", pipex->paths[0]);
	// printf("%s\n", pipex->paths[1]);
	// printf("%s\n", pipex->paths[2]);
	// printf("%s\n", pipex->paths[3]);
	// printf("%s\n", pipex->paths[4]);
	// printf("%s\n", pipex->paths[5]);
	// printf("%s\n", pipex->paths[6]);
	// printf("%s\n", pipex->cmd1[0]);
	// printf("%s\n", pipex->cmd1[1]);
	// printf("%s\n", pipex->cmd2[0]);
	// printf("%s\n", pipex->cmd2[1]);
	// printf("%s\n", pipex->path_exe);