/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:07:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/20 13:37:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_pipe(t_pipex *pipex, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		i;

	i = 0;
	if (pipe(fd) == -1)
		return (error(ERR_PIPE));
	pid1 = fork();
	if (pid1 == -1)
		return (error(ERR_FORK));
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		dup2((*pipex).infile, STDIN_FILENO);
		if ((*pipex).path_exe1 != NULL) // On execute la commande seulement si 
			execve((*pipex).path_exe1, (*pipex).cmd1, env);
		free_memory(*pipex); 
		exit(EXIT_FAILURE); // Quitte le programme donc en d'atre mots qui la memoire du child. 
	}
	pid2 = fork();
	if (pid2 == -1)
		return (error(ERR_FORK));
	if (pid2 == 0)
	{	
		dup2(fd[0], STDIN_FILENO);
		close (fd[1]);
		dup2((*pipex).outfile, STDOUT_FILENO);
		if ((*pipex).path_exe2 != NULL)
			execve((*pipex).path_exe2, (*pipex).cmd2, env);
		free_memory(*pipex);
		exit(EXIT_FAILURE);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}


// int	create_pipe(char **env)
// {
// 	int		fd[2];
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int		i;

// 	i = 0;
// 	if (pipe(fd) == -1)
// 		return (error(ERR_PIPE));
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return (error(ERR_FORK));
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close (fd[0]);
// 		dup2((*pipex).infile, STDIN_FILENO);
// 		execve((*pipex).path_exe1, (*pipex).cmd1, env);
// 	}
// 	pid2 = fork();
// 	if (pid2 == -1)
// 		return (error(ERR_FORK));
// 	if (pid2 == 0)
// 	{	
// 		dup2(fd[0], STDIN_FILENO);
// 		close (fd[1]);
// 		dup2((*pipex).outfile, STDOUT_FILENO);
// 		execve((*pipex).path_exe2, (*pipex).cmd2, env);
// 	}
// 	close (fd[0]);
// 	close (fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }
