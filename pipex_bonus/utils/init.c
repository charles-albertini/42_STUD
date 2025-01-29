/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlesalbertini <charlesalbertini@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:07:12 by calberti          #+#    #+#             */
/*   Updated: 2025/01/29 18:02:04 by charlesalbe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	error_arg(int argc)
{
	if (argc < 5)
	{
		ft_printf("Error: arguments\n");
		return (1);
	}
	return (0);
}

void    init_pipes(t_pipex *pipex, int cmd_count)
{
    int i;

    pipex->pipe_count = cmd_count - 1;
    pipex->pipes = malloc(sizeof(int *) * pipex->pipe_count);
    if (!pipex->pipes)
        return ;
    i = 0;
    while (i < pipex->pipe_count)
    {
        pipex->pipes[i] = malloc(sizeof(int) * 2);
        if (!pipex->pipes[i])
        {
            while (i > 0)
                free(pipex->pipes[--i]);
            free(pipex->pipes);
            return ;
        }
        if (pipe(pipex->pipes[i]) < 0)
        {
            perror("Pipe error");
            exit(1);
        }
        i++;
    }
}
