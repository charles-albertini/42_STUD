/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 06:07:12 by calberti          #+#    #+#             */
/*   Updated: 2025/01/17 06:14:11 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipex	init_pipex(int argc, char **argv)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf("Error: arguments\n");
		exit (1);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		perror("Error file1");
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
	{
		perror("Error file2");
		exit (1);
	}
	if (pipe(pipex.pipe) < 0)
	{
		perror("Error pipe");
		exit (1);
	}
	return (pipex);
}
