/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:10:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/19 16:10:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_memory(t_pipex pipex)
{
	free_dpointers(pipex.paths);
	free_dpointers(pipex.cmd1);
	free_dpointers(pipex.cmd2);
	free(pipex.path_exe1);
	free(pipex.path_exe2);	 
}

void	free_dpointers(char *args[])
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free (args);
}