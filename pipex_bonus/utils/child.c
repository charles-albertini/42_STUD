/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:50 by calberti          #+#    #+#             */
/*   Updated: 2025/02/06 18:35:38 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex *pipex, char **argv, char **envp, int here_doc, int argc)
{
	int flags = O_WRONLY | O_CREAT;
    flags |= here_doc ? O_APPEND : O_TRUNC;

    pipex->outfile = open(argv[argc - 1], flags, 0644);
    if (!here_doc)
    {
        pipex->infile = open(argv[1], O_RDONLY);
        if (pipex->infile < 0)
        {
			perror("Error file 1");
			close(pipex->pipes[0][0]);
			close(pipex->pipes[0][1]);
			free(pipex->pipes[0]);
			free(pipex->pipes);
			if (pipex->outfile != -1)
				close(pipex->outfile);
			free(pipex->pid);
            exit(1);
        }
    }
    dup2(pipex->infile, STDIN_FILENO);
    dup2(pipex->pipes[0][1], STDOUT_FILENO);
	if (pipex->infile != -1)
		close (pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	close_pipes(pipex);
	execute_command(pipex, argv[here_doc ? 3 : 2], envp);
}
void    child_process(t_pipex *pipex, char **argv, char **envp, int i, int here_doc, int argc)
{
    if (i == 0)
        first_child(pipex, argv, envp, here_doc, argc);	
    else if (i == pipex->pipe_count)
    {
        int flags = O_WRONLY | O_CREAT;
        flags |= here_doc ? O_APPEND : O_TRUNC;

        pipex->outfile = open(argv[argc - 1], flags, 0644);
        if (pipex->outfile < 0)
        {
			perror("Error file 2");
            close_pipes(pipex);
			free_pipes(pipex);
			free(pipex->pid);
            exit(1);
        }
        dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
        dup2(pipex->outfile, STDOUT_FILENO);
		close (pipex->outfile);
		if (pipex->infile != -1)
			close (pipex->infile);
    }
    else
    {
        dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
        dup2(pipex->pipes[i][1], STDOUT_FILENO);
    }

    close_pipes(pipex);
	if (pipex->infile != -1)
		close (pipex->infile);
    execute_command(pipex, argv[here_doc ? i + 3 : i + 2], envp);
}
