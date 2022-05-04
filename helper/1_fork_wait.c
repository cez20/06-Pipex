/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:21:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/20 17:04:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
	int id = fork(); // If I called function fork, a child process is created from the parent process and creates the same actions. 
	int n;
	int i;
	
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
	 	wait(NULL); // why is wait() not working and we must put use wait (NULL);
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
	}
	return (0);	
}