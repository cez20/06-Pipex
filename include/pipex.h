/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 14:42:09 by cemenjiv         ###   ########.fr       */
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

// *** MAIN.C ***
int 	main (int argc, char **argv, char *env[]);

// *** ERROR.C ***
int		msg(char *err);
char* 	msg_cmd(char *argv[], char *err);
char	**msg_path(char *err);

// *** INPUT_VALIDATION.C ***
int		open_infile(char **argv);
char	**split_path(char **env);
char	*valid_cmd(char **argv, char **path, char **cmd);
void	free_memory(char *args[]);

// ** PIPEX.C *** //
int pipex (char *path, char **cmd, int infile, char **env);

#endif