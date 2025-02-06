/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:51:47 by calberti          #+#    #+#             */
/*   Updated: 2025/02/06 17:32:17 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft/libft.h"
# include "libft/printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	pid_t		*pid;
	int			pipe_count; //nb de pipe necessaire
	int			**pipes; //tableau de pipe au lieu de pipe[2]
	char		**paths;
	char		**cmd_args;
	char		*cmd;
}	t_pipex;

void	free_array(char **arr);
void	free_pipex(t_pipex *pipex);
char	*find_command_path(char *cmd, char **envp);
void	execute_command(t_pipex *pipex, char *raw_cmd, char **envp);
void	second_child(t_pipex *pipex, char **argv, char **envp);
// void	first_child(t_pipex *pipex, char **argv, char **envp);
void	first_child(t_pipex *pipex, char **argv, char **envp, int here_doc, int argc);
int		error_arg(int argc);
void	error_file(t_pipex *pipex);
void	error_dup(t_pipex *pipex);
void	error_dup_2(t_pipex *pipex);

// Nouvelles déclarations à ajouter
void    init_pipes(t_pipex *pipex, int cmd_count);
void    close_pipes(t_pipex *pipex);
void    free_pipes(t_pipex *pipex);
void    child_process(t_pipex *pipex, char **argv, char **envp, int i, int here_doc, int argc);
void    handle_here_doc(t_pipex *pipex, char *limiter);
int     is_here_doc(char *arg);

#endif
