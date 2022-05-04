/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:47:28 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 08:06:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/errno.h> // Library needed for errno command below. 

// Video called "CAlling fork multiple times"
// 2:36- 8:20 -> Explanation of the different fork branches with drawing 
//


int main (int argc, char **argv)
{
	int id1 = fork(); // First fork is done
	int id2 = fork(); // second fork is done
	if (id1 == 0)  // Si le id correspond au child du premier fork. 
	{
		if (id2 == 0)
			printf("We are process y\n");// Si id2 == 0 = s'il s'agit du child du child 
		else
			printf("We are process x\n"); // Sinon, il s'agit du child du parent process 
	}
	else // Si le id1 n'est pas 0 cela veut dire que nous sommes dans le 2e fork
	{
		if (id2 == 0) // Il s'agit du 2e child du parent process 
			printf("We are in process z\n");
		else
			printf("We are the parent process\n"); // Il s'agit du parent process (main)
	}
	while (wait(NULL) != -1 || errno != ECHILD) // wait(NULL) returns -1 when there is nothing to wait for. Else, it means that we must wait for process. 
		printf("Waited for a child to finish\n");
	return (0);	
	}