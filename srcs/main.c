/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 16:08:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	*cmd_path1;
	char	*cmd_path2;
	int		infile;
	int		outfile;

	paths = NULL;
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	if (argc != 5)
		return (msg(ERR_ARG));
	infile = open_infile(argv);
	outfile = open(argv[argc - 1], O_CREAT, S_IRUSR | S_IWUSR, 0644);
	paths = split_path(env);
	cmd_path1 = valid_cmd(argv, paths, cmd1);
	cmd_path2 = valid_cmd1(argv, paths, cmd2);
	pipex(cmd_path1, cmd_path2, cmd1, cmd2, infile, outfile, env);
	
	//ELEMENTS TO REMEMBER TO FREE
	free_memory(paths); // free_memory function is used with double pointers. 
	free_memory(cmd1);
	free_memory(cmd2);
	free(cmd_path1);
	free(cmd_path2);
	return (0);
}
