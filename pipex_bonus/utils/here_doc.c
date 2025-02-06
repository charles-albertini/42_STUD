#include "../pipex.h"

int is_here_doc(char *arg)
{
    return (arg && !ft_strncmp(arg, "here_doc", 9)); // arg && pour eviter de segfault si il n'y a pas d'arg, ! pour renvoyer 1 au lieu de 0
}

void    handle_here_doc(t_pipex *pipex, char *limiter)
{
    char    *line;
    int     temp_fd;

    temp_fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (temp_fd < 0)
    {
        perror("here_doc");
        exit(1);
    }
    while (1)
    {
        ft_putstr_fd("heredoc> ", 1);
        line = get_next_line(0);
        if (!line)
            break ;
        if (!ft_strncmp(line, limiter, ft_strlen(limiter)) &&
            line[ft_strlen(limiter)] == '\n')
        {
            free(line);
            break ;
        }
        ft_putstr_fd(line, temp_fd);
        free(line);
    }
    close(temp_fd);
    pipex->infile = open(".here_doc_tmp", O_RDONLY);
    if (pipex->infile < 0)
    {
        unlink(".here_doc_tmp");
		close(pipex->infile);
        exit(1);
    }
}
