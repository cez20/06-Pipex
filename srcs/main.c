/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/20 10:19:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Elements a ameliorer 
// Fonction create_commands qui est capable de prendre un nombre infini de commande ou bien qui cree une commande l'utilise et l'efface une fois termine
//Fonction merge path: qui fusionne le path et la commande
// Breakdown de create pipe pour qu'elle rentre dans 25 lignes
// Changer le &pipex des fonctions pour l'element utilise (ex: pipex.command)
// Creer un script pour tester toutes les combinaisons possibles. 
// Memory leaks quand les 2 commandes ou une des 2 commandes sont errone ou
// LORSQUE la 1ere commande est errone est la 2e ne l'est pas. 

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	if (argc == 5)
	{	
		pipex.infile = open_infile(argv);
		pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
		pipex.paths = split_path(env);
		create_commands(&pipex, argv);
		pipex.path_exe1 = merge_paths_cmd1(&pipex);
		pipex.path_exe2 = merge_paths_cmd2(&pipex);
		create_pipe(&pipex, env);
		free_memory(pipex);
	}	
	else
		return (error(ERR_ARG));
	return (0);
}




