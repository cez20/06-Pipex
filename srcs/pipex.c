/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:07:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 12:34:05 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	first_child(char *path, char **cmd, int infile, char **env, pid_t pid1)
// {
// 	pid1 = fork(); // Creates a parent and a child
// 	if (pid1 == -1)
// 		return (msg(ERR_FORK)); 
// 	if (pid == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
// 	{
// 		close (fd[0]); // Close read end of pipe because not used. 
// 		dup2(infile, STDIN_FILENO); //Child will read from infile (fd = 3) instead from STDIN (0) au moment out il execute la commande. 
// 		dup2(fd[1], STDOUT_FILENO); // the first command will be executed and written not on STDOUT but rather in fd[1] which is the readable end of the pipe
// 		execve(path, cmd, env);
// 	}
// }

// void	second_child(char *path, char **cmd, int infile, char **env, pid_t pid)
// {
// 	pid = fork(); // Creates a parent and a child
// 	if (pid == -1)
// 		return (msg(ERR_FORK)); 
// 	if (pid == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
// 	{
// 		close (fd[1]); // Close read end of pipe because not used. 
// 		dup2(outfile, STDOUT_FILENO); //Child will read from infile (fd = 3) instead from STDIN (0) au moment out il execute la commande. 
// 		dup2(fd[0], STDIN_FILENO); // the first command will be executed and written not on STDOUT but rather in fd[1] which is the readable end of the pipe
// 		execve(path, cmd, env);
// 	}
// }

int pipex (char *path, char **cmd, int infile, char **env)
{
	int 	fd[2];
	pid_t	pid1;
	//pid_t	pid2;

	if (pipe(fd) == -1) // Creates a pipe
		return (msg(ERR_PIPE));
	pid1 = fork(); // Creates a parent and a child
	if (pid1 == -1)
		return (msg(ERR_FORK)); 
	if (pid1 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	{
		close (fd[0]); // Close read end of pipe because not used. 
		dup2(infile, STDIN_FILENO); //Child will read from infile (fd = 3) instead from STDIN (0) au moment out il execute la commande. 
		dup2(fd[1], STDOUT_FILENO); // the first command will be executed and written not on STDOUT but rather in fd[1] which is the readable end of the pipe
		execve(path, cmd, env);
	}

	waitpid(pid1, NULL, 0);
	return (0);
}

