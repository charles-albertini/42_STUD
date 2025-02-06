/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:59:09 by calberti          #+#    #+#             */
/*   Updated: 2025/02/06 19:35:34 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_command_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*temp_path;

	i = 0;
	if (!cmd || !*cmd)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(full_path, X_OK) == 0)
			return (free_array(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_array(paths), NULL);
}

void	execute_command(t_pipex *pipex, char *raw_cmd, char **envp)
{
	pipex->cmd_args = ft_split(raw_cmd, ' ');
	if (!pipex->cmd_args)
	{
		free_pipex(pipex);
		ft_putstr_fd("Error args\n", 2);
		exit (1);
	}
	if (access(pipex->cmd_args[0], X_OK) == 0)
		pipex->cmd = pipex->cmd_args[0];
	else
		pipex->cmd = find_command_path(pipex->cmd_args[0], envp);
	if (!pipex->cmd)
	{
		free_pipex(pipex);
		ft_putstr_fd("Error command not found\n", 2);
		close_pipes(pipex);
		free_pipes(pipex);
		free(pipex->pid);
		exit (1);
	}
	if (execve(pipex->cmd, pipex->cmd_args, envp) == -1)
	{
		close_pipes(pipex);
		free_pipes(pipex);
		free(pipex->pid);
		free_pipex(pipex);
		ft_putstr_fd("Error execve\n", 2);
		exit (1);
	}
}
