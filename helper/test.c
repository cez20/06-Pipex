/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:30:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/06 15:51:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> // allows to use the strerror 


int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <filename>\n", argv[0]); // command that essentially states how to use program correctly. 
		exit (-1);
	}
	int fd;
	fd = open (argv[1], O_RDONLY);
	// if (fd == -1)
	// {
	// 	fprintf(stderr, "errno =  %s\n", strerror(errno));// Command that allows to print a message stating what mistake is. 
	// 	exit (-1);
	// }
	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}
	char c;
	while (read(fd, &c, 1) > 0)
	{	
		fputc(c,stdout);
	}	


}