/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:01:24 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/27 11:08:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// The myfifo1 file does not pop up until I decide to remove the a.out from my file

int main (int agrc, char **argv)
{
	int id = fork(); // If I called function fork, a child process is created from the parent process and creates the same actions. 
	printf("Hello World! from id : %d\n", id);
	if (id != 0)
		fork();
	printf("Hello World! from id : %d\n", id);
	return (0);	
}