/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:59:11 by calberti          #+#    #+#             */
/*   Updated: 2025/02/06 19:07:51 by calberti         ###   ########.fr       */
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

void    free_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->pipe_count)
    {
        free(pipex->pipes[i]);
        i++;
    }
    free(pipex->pipes);
}

void    close_pipes(t_pipex *pipex)
{
    int i;

    i = 0;
    while (i < pipex->pipe_count)
    {
        close(pipex->pipes[i][0]);
        close(pipex->pipes[i][1]);
        i++;
    }
}
