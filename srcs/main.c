/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/24 12:37:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		command_execution(&pipex, env);
		free_memory(pipex);
	}
	else
		return (error(ERR_ARG));
	return (0);
}
