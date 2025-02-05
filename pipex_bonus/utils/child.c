/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:50 by calberti          #+#    #+#             */
/*   Updated: 2025/02/01 18:19:31 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    child_process(t_pipex *pipex, char **argv, char **envp, int i, int here_doc, int argc)
{
    if (i == 0)
    {
        if (!here_doc)
        {
            pipex->infile = open(argv[1], O_RDONLY);
            if (pipex->infile < 0)
            {
                close_pipes(pipex);
                exit(1);
            }
        }
        dup2(pipex->infile, STDIN_FILENO);
        dup2(pipex->pipes[i][1], STDOUT_FILENO);
    }
    else if (i == pipex->pipe_count)
    {
        int flags = O_WRONLY | O_CREAT;
        flags |= here_doc ? O_APPEND : O_TRUNC;

        pipex->outfile = open(argv[argc - 1], flags, 0644);
        if (pipex->outfile < 0)
        {
            close_pipes(pipex);
            exit(1);
        }
        dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
        dup2(pipex->outfile, STDOUT_FILENO);
    }
    else
    {
        dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
        dup2(pipex->pipes[i][1], STDOUT_FILENO);
    }

    close_pipes(pipex);
    execute_command(pipex, argv[here_doc ? i + 3 : i + 2], envp);
}
