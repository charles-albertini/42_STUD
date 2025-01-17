/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:51:42 by calberti          #+#    #+#             */
/*   Updated: 2025/01/17 08:08:25 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	pid_t	pid1;
	pid_t	pid2;

	if (error_arg(argc) == 1)
		return (1);
	if (pipe(pipex.pipe) < 0)
		return (perror("Error pipe"),1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Error fork"), 1);
	if (pid1 == 0)
		first_child(&pipex, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Error fork"), 1);
	if (pid2 == 0)
		second_child(&pipex, argv, envp);
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
