/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 07:43:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/20 17:20:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd, char *err)
{
	char	*string;

	string = ft_strjoin("bash: ", cmd);
	write(2, string, ft_strlen(string));
	write(2, err, ft_strlen(err));
	free(string);
}

char	**error_path(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}
