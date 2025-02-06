/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:51:42 by calberti          #+#    #+#             */
/*   Updated: 2025/02/06 18:33:53 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    int     i;
    int     cmd_count;
    // pid_t   *pipex.pid;
    int     here_doc;
	
	pipex.infile = -1;
    here_doc = is_here_doc(argv[1]);
    if ((!here_doc && argc < 5) || (here_doc && argc < 6))
        return (ft_printf("Error: invalid number of arguments\n"), 1);

    cmd_count = here_doc ? argc - 4 : argc - 3;
    init_pipes(&pipex, cmd_count);

    if (here_doc)
        handle_here_doc(&pipex, argv[2]);

    pipex.pid = malloc(sizeof(pid_t) * cmd_count);
    if (!pipex.pid)
        return (1);

    i = -1;
    while (++i < cmd_count)
    {
        pipex.pid[i] = fork();
        if (pipex.pid[i] < 0)
            return (perror("Fork error"), 1);
        if (pipex.pid[i] == 0)
            child_process(&pipex, argv, envp, i, here_doc, argc);
    }

    close_pipes(&pipex);
    i = -1;
    while (++i < cmd_count)
        waitpid(pipex.pid[i], NULL, 0);

    if (here_doc)
		unlink(".here_doc_tmp");
	if (pipex.infile != -1)
		close(pipex.infile);
    free(pipex.pid);
    free_pipes(&pipex);
    return (0);
}
