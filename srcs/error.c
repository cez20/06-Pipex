/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:43:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 07:50:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err)); // fd == 2 because associated with STDERR. 
	exit(EXIT_FAILURE);
}

char* msg_cmd(char *argv[], char *err)
{
	char *string;
	
	string = ft_strjoin("bash: ", argv[2]);
	write(2, string, ft_strlen(string));
	write(2, err, ft_strlen(err)); 
	exit (EXIT_FAILURE);
}

char	**msg_path(char *err)
{
	write(2, err, ft_strlen(err)); // fd == 2 because associated with STDERR. 
	exit(EXIT_FAILURE);
}