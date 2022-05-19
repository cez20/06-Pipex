/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/19 16:51:06 by cemenjiv         ###   ########.fr       */
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

#define ERR_ARG "Invalid number of arguments!\n"
#define ERR_PATH "There is no PATH in the ENV\n" // a valider si c'est necessaire, car il y a tjrs PATH
#define ERR_CMD ": command not found\n"
#define ERR_PIPE "Pipe creation is impossible\n"
#define ERR_FORK "Fork() command has a problem\n"

typedef struct s_pipex
{
    int     infile;
    int     outfile;
    char    **paths;
    char    **cmd1;
    char    **cmd2;
    char    *path_exe1;
	char	*path_exe2;
}           t_pipex;

// *** MAIN.C ***
int 	main (int argc, char **argv, char *env[]);
t_pipex	*initialize_pipex();
void	free_dpointers(char *args[]);
void	free_memory(t_pipex pipex);

// *** ERROR.C ***
int		error(char *err);
char	**error_path(char *err);
void	error_cmd(char *cmd, char *err);

// *** INPUT_VALIDATION.C ***
int		open_infile(char **argv);
char	**split_path(char **env);
void	create_commands(t_pipex *pipex, char **argv);
char	*merge_paths_cmd1(t_pipex *pipex);
char	*merge_paths_cmd2(t_pipex *pipex);

// ** PIPEX.C *** //
int create_pipe (t_pipex *pipex, char **env);

#endif