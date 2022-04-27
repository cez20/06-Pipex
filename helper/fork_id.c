/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:22:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/21 13:20:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char **argv)
{
	int id = fork();
	if (id == 0)
		sleep (5);
	printf("Current ID :%d , parent ID: %d\n", getpid(), getppid());
	if (id != 0)
		wait (NULL);  // wait is important here, because otherwise parent finished before child
	return (0);
}