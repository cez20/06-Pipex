/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/26 19:17:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h> // Library in order to use mkfifo
# include <sys/wait.h> // Library in order to use mkfifo
# include <sys/errno.h> // Library needed for errno command below. 
# include "../libft/libft.h"

# define ERR_ARG "Invalid number of arguments!\n"
# define ERR_PATH "There is no PATH in the ENV\n" 
# define ERR_CMD ": command not found\n"
# define ERR_PIPE "Pipe creation is impossible\n"
# define ERR_FORK "Fork() command has a problem\n"

typedef struct s_pipex
{
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	*path_exe1;
	char	*path_exe2;
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;	
}		t_pipex;

// *** MAIN.C ***
int		main(int argc, char **argv, char *env[]);

// *** FREE.C ***
void	free_dpointers(char *args[]);
void	free_memory(t_pipex pipex);

// *** ERROR_HANDLING.C ***
int		error(char *err);
char	**error_path(char *err);
void	error_cmd(char *cmd, char *err);

// *** INPUT_VALIDATION.C ***
void	open_infile(char **argv, int *infile);
char	**split_path(char **env);
void	create_commands(t_pipex *pipex, char **argv);
char	*merge_paths_cmd1(t_pipex *pipex);
char	*merge_paths_cmd2(t_pipex *pipex);

// ** PIPEX.C *** //
int		command_execution(t_pipex *pipex, char **env);
void	first_fork(t_pipex *pipex, char **env);
void	second_fork(t_pipex *pipex, char **env);

#endif