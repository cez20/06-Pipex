/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:07:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/24 13:13:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	command_execution(t_pipex *pipex, char **env)
{
	if (pipe(pipex->fd) == -1)
		return (error(ERR_PIPE));
	first_fork(pipex, env);
	second_fork(pipex, env);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	return (0);
}

void	first_fork(t_pipex *pipex, char **env)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		error(ERR_FORK);
	if (pipex->pid1 == 0)
	{
		close (pipex->fd[0]);
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		if (pipex->path_exe1 != NULL && pipex->infile != -1)
			execve(pipex->path_exe1, pipex->cmd1, env);
		free_memory(*pipex);
		exit (EXIT_FAILURE);
	}
}

void	second_fork(t_pipex *pipex, char **env)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		error(ERR_FORK);
	if (pipex->pid2 == 0)
	{	
		close (pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		if (pipex->path_exe2 != NULL)
			execve(pipex->path_exe2, pipex->cmd2, env);
		free_memory(*pipex);
		exit (EXIT_FAILURE);
	}
}
