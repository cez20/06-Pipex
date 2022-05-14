/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:58:28 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/14 14:31:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	file_validation(int argc, char **argv)
{
	char	*string;

	if (access(argv[1], F_OK) == -1)
	{
		string = ft_strjoin("bash: ", argv[1]);
		perror(string);
		exit (EXIT_FAILURE);
	}
	if (access(argv[argc - 1], F_OK) == -1) // If I cannot access last argument, because it doesnt exist 
		open(argv[argc - 1], O_CREAT , S_IRUSR | S_IWUSR); // then create an open a file name lik last arguments
}