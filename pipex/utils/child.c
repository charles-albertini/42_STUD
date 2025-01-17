/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:50 by calberti          #+#    #+#             */
/*   Updated: 2025/01/17 07:59:46 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror("Error file1");
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		exit (1);
	}
	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pipe[1], STDOUT_FILENO);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	execute_command(pipex, argv[2], envp);
}

void	second_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
	{
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		perror("Error file2");
		exit (1);
	}
	dup2(pipex->pipe[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->outfile);
	execute_command(pipex, argv[3], envp);
}
