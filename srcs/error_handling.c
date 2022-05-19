/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:43:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/18 22:41:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	msg_cmd1(char *argv, char *err)
{
	char	*string;

	string = ft_strjoin("bash: ", argv);
	write(2, string, ft_strlen(string));
	write(2, err, ft_strlen(err));
}

void	msg_cmd2(char **argv, char *err)
{
	char	*string;

	string = ft_strjoin("bash: ", argv[3]);
	write(2, string, ft_strlen(string));
	write(2, err, ft_strlen(err));
}

char	**msg_path(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}
