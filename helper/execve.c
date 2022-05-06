/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:07:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/10 15:09:07 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h> // Library in order to use mkfifo
# include <sys/wait.h> // Library in order to use mkfifo
# include <sys/errno.h> // Library needed for errno command below. 
# include "../libft/libft.h"

int main (int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	char *path = "/Users/cemenjiv/Desktop/42Quebec/push_swap/push_swap"; // Donne le absolute path de mon programme push_swap (le programme doit etre compile)
	char *argV[] = {"push_swap", "4", "1", "2", "9", "48", "100", "67", NULL}; // Donne les arguments

	if(execve(path, argV, envp) == -1)
		printf("Could not execute exec!\n");
	printf("Oops, something is wrong\n");
	return (0); // Le programma va afficher toutes les operations 
}


// int main (int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	char *path = "/bin/ls";
// 	char *argV[] = {"ls", "-la", NULL};

// 	if(execve(path, argV, envp) == -1)
// 		printf("Could not execute exec!\n");
// 	printf("Oops, something is wrong\n");

// 	return (0);
// }
