/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 13:22:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[], char *env[])
{
	char	**paths;
	char	**cmd;
	char	*cmd_path;
	int 	infile;
	int		outfile;

	paths = NULL;
	cmd = ft_split(argv[2], ' '); // This command could be put between "paths" and "command paths"
	if (argc != 5)
		return (msg(ERR_ARG));
	infile = open_infile(argv);
	outfile = open(argv[argc - 1], O_CREAT , S_IRUSR | S_IWUSR);
	paths = split_path(env);
	cmd_path = valid_cmd(argv, paths, cmd);
	pipex(cmd_path, cmd, infile, env);
	
	
	//ELEMENTS TO REMEMBER TO FREE
	free_memory(paths); // free_memory function is used with double pointers. 
	free_memory(cmd);
	free(cmd_path);
	return (0);	
}
