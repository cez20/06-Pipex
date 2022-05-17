/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 22:23:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	*pipex;
	int		i;
	i = 0;

	if (argc != 5)
		return (msg(ERR_ARG));
	pipex = malloc(sizeof(pipex));
	pipex->infile = open_infile(argv);
	pipex->outfile = open(argv[argc - 1], O_CREAT, S_IRUSR | S_IWUSR, 0644);
	create_path_exe(argv, env, pipex);
	while(pipex->paths[i]) // Pkoi les paths ne suivent pas
	{
		printf("%s\n", pipex->paths[i]);
		i++;
	}
	//pipex->paths = split_path(env);
	//create_commands(pipex, argv);
	//pipex->path_exe = merge_paths_commands(pipex);
	//pipex(cmd_path1, cmd_path2, cmd1, cmd2, infile, outfile, env);
	
	//ELEMENTS TO REMEMBER TO FREE
	free_memory(pipex->paths); // free_memory function is used with double pointers. 
	//free_memory(cmd1);
	//free_memory(cmd2);
	//free(cmd_path1);
	//free(cmd_path2);
	return (0);
}
