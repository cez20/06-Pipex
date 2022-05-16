/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:07:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 16:13:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int pipex (char *path1, char *path2, char **cmd1, char **cmd2, int infile, int outfile, char **env)
{
	int 	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1) // Creates a pipe
		return (msg(ERR_PIPE));
	pid1 = fork(); // Creates a parent and a child
	if (pid1 == -1)
		return (msg(ERR_FORK)); 
	if (pid1 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	{
		printf("Helloe I<m in the first child process");
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]); 
		dup2(infile, STDIN_FILENO);  
		execve(path1, cmd1, env);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (msg(ERR_FORK)); 
	if (pid2 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	{	
		printf("Helloe I<m in the second child process");
		dup2(fd[0], STDIN_FILENO); 
		close (fd[1]); 
		dup2(outfile, STDOUT_FILENO); 
		execve(path2, cmd2, env);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

