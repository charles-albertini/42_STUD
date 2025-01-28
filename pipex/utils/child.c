/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:58:50 by calberti          #+#    #+#             */
/*   Updated: 2025/01/21 20:01:17 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
<<<<<<< HEAD
		error_file(pipex, "Error file1");
=======
		error_file(pipex);
		close(pipex->outfile);
>>>>>>> 5bc0fde38c2b86b914631fed60e1b994f967cd8b
		exit (1);
	}
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
	{
		error_dup(pipex);
		exit (1);
	}
	if (dup2(pipex->pipe[1], STDOUT_FILENO) < 0)
	{
		error_dup(pipex);
		exit (1);
	}
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
	execute_command(pipex, argv[2], envp);
}

void	second_child(t_pipex *pipex, char **argv, char **envp)
{
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex->outfile < 0)
	{
		error_file(pipex, "Error file2");
		exit (1);
	}
	if (dup2(pipex->pipe[0], STDIN_FILENO) < 0)
	{
		error_dup_2(pipex);
		exit (1);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) < 0)
	{
		error_dup_2(pipex);
		exit (1);
	}
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->outfile);
	execute_command(pipex, argv[3], envp);
}
