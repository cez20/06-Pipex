/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:58:28 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/03 15:20:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	input_validation(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("First argument is not an input\n");
		exit (EXIT_FAILURE);
	}
	else
		printf("Input is valid! Please continue!\n");
	close (fd); // Close this argv, because it is lo longer needed. 
}