/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/18 23:56:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Elements a ameliorer 
// Fonction create_commands qui est capable de prendre un nombre infini de commande ou bien qui cree une commande l'utilise et l'efface une fois termine
//Fonction merge path: qui fusionne le path et la commande
// Breakdown de create pipe pour qu'elle rentre dans 25 lignes
// Fonction free qui libere tout en meme temps.
// Changer le &pipex des fonctions pour l'element utilise (ex: pipex.command)
// Creer un script pour tester toutes les combinaisons possibles. 


int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	
	if (argc == 5)
	{	
		pipex.infile = open_infile(argv);
		pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		pipex.paths = split_path(env);
		create_commands(&pipex, argv);
		pipex.path_exe1 = merge_paths_commands(&pipex);
		pipex.path_exe2 = merge_paths_commands1(&pipex);
		create_pipe(&pipex, env);
		free_memory(pipex.paths);
		free_memory(pipex.cmd1);
		free_memory(pipex.cmd2);
		free(pipex.path_exe1);
		free(pipex.path_exe2);
	}	
	else
		return (msg(ERR_ARG));
	return (0);
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