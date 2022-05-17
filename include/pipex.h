/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 22:24:56 by cemenjiv         ###   ########.fr       */
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
    char    *path_exe;
}       t_pipex;

// *** MAIN.C ***
int 	main (int argc, char **argv, char *env[]);

// *** ERROR.C ***
int		msg(char *err);
void	msg_cmd1(char *argv, char *err);
char	**msg_path(char *err);

// *** INPUT_VALIDATION.C ***
int		open_infile(char **argv);
void	create_path_exe(char **argv, char **env, t_pipex *pipex);
char	**split_path(char **env);
void	create_commands(t_pipex *pipex, char **argv);
char	*merge_paths_commands(t_pipex *pipex);
void	free_memory(char *args[]);

// ** PIPEX.C *** //
int pipex (char *path1, char *path2, char **cmd1, char **cmd2, int infile, int outfile, char **env);

#endif