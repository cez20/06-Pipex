/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/16 14:47:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		open_infile(char **argv)
{
	char	*string;
	int 	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		string = ft_strjoin("bash: ", argv[1]);
		perror(string);
		exit (EXIT_FAILURE);
	}
	return (infile);
}

char	**split_path(char **env)
{
	int 	i;

	i = 0;
	while(env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return(ft_split(&env[i][5], ':'));
		i++;
	}
	return (msg_path(ERR_PATH));
}

char	*valid_cmd(char **argv, char **path, char **cmd)
{
	char	*tmp;
	char	*command;

	while(*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(command, X_OK) != -1)
			return (command);
		free(command);
		path++;
	}
	return (msg_cmd(argv, ERR_CMD));
}

void	free_memory(char *args[])
{
	int i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free (args);
}
