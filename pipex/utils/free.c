/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:59:11 by calberti          #+#    #+#             */
/*   Updated: 2025/01/21 20:01:41 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	if (pipex->cmd_args)
	{
		i = 0;
		while (pipex->cmd_args[i])
		{
			free(pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->cmd)
		free(pipex->cmd);
}

void	error_file(t_pipex *pipex, char *err)
{
	perror(err);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	error_dup(t_pipex *pipex)
{
	perror("dup2");
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
}

void	error_dup_2(t_pipex *pipex)
{
	perror("dup2");
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->outfile);
}
