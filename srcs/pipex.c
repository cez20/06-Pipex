/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:07:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/17 17:20:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int create_pipe (t_pipex *pipex, char **env)
{
	int 	fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int 	i;

	i = 0;
	if (pipe(fd) == -1) // Creates a pipe
		return (msg(ERR_PIPE));
	pid1 = fork(); // Creates a parent and a child
	if (pid1 == -1)
		return (msg(ERR_FORK));
	if (pid1 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	{
		printf("Hello I'm in the first child process\n");
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]); 
		dup2(pipex->infile, STDIN_FILENO);  
		execve(pipex->path_exe1, pipex->cmd1, env);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (msg(ERR_FORK)); 
	if (pid2 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	{	
		printf("Hello I'm in the second child process\n");
		dup2(fd[0], STDIN_FILENO); 
		close (fd[1]); 
		dup2(pipex->outfile, STDOUT_FILENO); 
		execve(pipex->path_exe2, pipex->cmd2, env);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid2, NULL, 0); // It seems like the solution to wait for pid2 before pid1.
	waitpid(pid1, NULL, 0);
	return (0);
}

//pid_t	pid2;

// pid2 = fork();
	// if (pid2 == -1)
	// 	return (msg(ERR_FORK)); 
	// if (pid2 == 0) // Le child vient modifier les parametres de base du parent sans modifier le parent. 
	// {	
	// 	printf("Helloe I<m in the second child process");
	// 	dup2(fd[0], STDIN_FILENO); 
	// 	close (fd[1]); 
	// 	dup2(outfile, STDOUT_FILENO); 
	// 	execve(path2, cmd2, env);
	// }

	//