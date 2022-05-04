/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_exec_other_program.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:04:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/04 13:10:44 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> // Library in order to use mkfifo
#include <sys/wait.h> // Library in order to use mkfifo
#include <sys/errno.h> // Library needed for errno command below. 
#include <fcntl.h>
#include <time.h> // necessary for srand(time(NULL) command 

// Video is entitle "How to execute another program using C (using exec)"
// This video did not seem important for the pipex project 

int main (int argc, char *argv[])
{
	_execl
	return (0);	
}