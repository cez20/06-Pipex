/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/05/20 16:39:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char **argv)
{
	char	*string;
	int		infile;

	infile = open(argv[1], O_RDWR);
	if (infile == -1)
	{
		string = ft_strjoin("bash: ", argv[1]);
		perror(string);
		free(string);
		exit (EXIT_FAILURE);
	}
	return (infile);
}

char	**split_path(char **env)
{
	char	**str;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			str = ft_split(&env[i][5], ':');
			return (str);
		}
		i++;
	}
	return (error_path(ERR_PATH));
}

void	create_commands(t_pipex *pipex, char **argv)
{
	(*pipex).cmd1 = ft_split(argv[2], ' ');
	(*pipex).cmd2 = ft_split(argv[3], ' ');
}

char	*merge_paths_cmd1(t_pipex *pipex)
{
	char	*path;
	char	*cmd_exe;
	int		i;

	i = 0;
	while (pipex->paths[i])
	{
		path = ft_strjoin(pipex->paths[i], "/");
		cmd_exe = ft_strjoin(path, pipex->cmd1[0]);
		free(path);
		if (access(cmd_exe, X_OK) != -1)
			return (cmd_exe);
		free(cmd_exe);
		i++;
	}
	error_cmd(pipex->cmd1[0], ERR_CMD);
	return (NULL);
}

char	*merge_paths_cmd2(t_pipex *pipex)
{
	char	*tmp;
	char	*cmd_exe;
	int		i;

	i = 0;
	while ((*pipex).paths[i])
	{
		tmp = ft_strjoin(pipex->paths[i], "/");
		cmd_exe = ft_strjoin(tmp, pipex->cmd2[0]);
		free(tmp);
		if (access(cmd_exe, X_OK) != -1)
			return (cmd_exe);
		free(cmd_exe);
		i++;
	}
	error_cmd(pipex->cmd2[0], ERR_CMD);
	return (NULL);
}
