#include "minishell.h"

static t_redir *get_last_redir_of_type(t_redir **redirs, int type)
{
    int     i;
    t_redir *last;

    i = 0;
    last = NULL;
    while (redirs[i])
    {
        // Modifions cette condition pour accepter REDIROUT et APPEND
        if (redirs[i]->type == type || 
            (type == REDIROUT && redirs[i]->type == APPEND))
            last = redirs[i];
        i++;
    }
    return (last);
}
static t_heredoc_data *create_heredoc_data(char *delimiter)
{
    static int count = 0;
    t_heredoc_data *data;
    char *num;

    data = malloc(sizeof(t_heredoc_data));
    if (!data)
        return NULL;
    
    num = ft_itoa(count++);
    data->filename = ft_strjoin("/tmp/.heredoc_", num);
    free(num);
    
    if (!data->filename)
    {
        free(data);
        return NULL;
    }
    
    data->delimiter = ft_strdup(delimiter);
    if (!data->delimiter)
    {
        free(data->filename);
        free(data);
        return NULL;
    }
    
    data->fd = -1;
    return data;
}

static void free_heredoc_data(t_heredoc_data *data)
{
    if (!data)
        return;
    if (data->fd != -1)
        close(data->fd);
    unlink(data->filename);
    free(data->filename);
    free(data->delimiter);
    free(data);
}

static int process_single_heredoc(t_heredoc_data *data)
{
    char    *line;
    int     fd;
    size_t  len;

    // Vérification des paramètres
    if (!data || !data->delimiter || !data->filename)
        return (-1);

    // Ouverture du fichier temporaire
    fd = open(data->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (-1);

    // Boucle de lecture du here-doc
    while (1)
    {
        ft_putstr_fd("> ", 1);
        line = get_next_line(STDIN_FILENO);
        
        // Gérer EOF ou erreur de lecture
        if (!line)
        {
            close(fd);
            return (-1);
        }

        // Retirer le retour à la ligne final s'il existe
        len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        // Vérifier si c'est le délimiteur
        if (strcmp(line, data->delimiter) == 0)
        {
            free(line);
            break;
        }

        // Remettre le retour à la ligne pour l'écriture
        line[len - 1] = '\n';
        
        // Écrire la ligne dans le fichier
        if (write(fd, line, len) < 0)
        {
            free(line);
            close(fd);
            return (-1);
        }
        free(line);
    }
    
    close(fd);
    
    // Réouvrir le fichier en lecture pour l'utilisation ultérieure
    fd = open(data->filename, O_RDONLY);
    if (fd < 0)
        return (-1);
        
    data->fd = fd;
    return (0);
}

static t_heredoc_data **prepare_heredocs(t_command *cmd)
{
    int i = 0, count = 0;
    t_heredoc_data **heredocs;

    // Compter le nombre de here_doc
    while (cmd->redir && cmd->redir[i])
    {
        if (cmd->redir[i]->type == HERE_DOC)
            count++;
        i++;
    }

    if (count == 0)
        return NULL;

    heredocs = malloc(sizeof(t_heredoc_data *) * (count + 1));
    if (!heredocs)
        return NULL;

    i = 0;
    count = 0;
    while (cmd->redir && cmd->redir[i])
    {
        if (cmd->redir[i]->type == HERE_DOC)
        {
            heredocs[count] = create_heredoc_data(cmd->redir[i]->file);
            if (!heredocs[count])
            {
                // Nettoyer en cas d'erreur
                while (--count >= 0)
                    free_heredoc_data(heredocs[count]);
                free(heredocs);
                return NULL;
            }
            count++;
        }
        i++;
    }
    heredocs[count] = NULL;
    return heredocs;
}

int process_heredocs(t_shell *shell)
{
    t_command *cmd;
    t_heredoc_data **heredocs;
    int i;

    cmd = shell->cmds;
    while (cmd)
    {
        heredocs = prepare_heredocs(cmd);
        if (!heredocs)
        {
            if (cmd->redir && get_last_redir_of_type(cmd->redir, HERE_DOC))
                return -1;
            cmd = cmd->next;
            continue;
        }

        i = 0;
        while (heredocs[i])
        {
            if (process_single_heredoc(heredocs[i]) < 0)
            {
                // Nettoyer en cas d'erreur
                while (heredocs[i])
                    free_heredoc_data(heredocs[i++]);
                free(heredocs);
                return -1;
            }
            i++;
        }

        // Stocker les FDs pour une utilisation ultérieure
        i = 0;
        int redir_idx = 0;
        while (cmd->redir[redir_idx])
        {
            if (cmd->redir[redir_idx]->type == HERE_DOC)
            {
                free(cmd->redir[redir_idx]->file);
                cmd->redir[redir_idx]->file = ft_strdup(heredocs[i]->filename);
                i++;
            }
            redir_idx++;
        }

        // Nettoyer les données des heredocs
        i = 0;
        while (heredocs[i])
            free_heredoc_data(heredocs[i++]);
        free(heredocs);

        cmd = cmd->next;
    }
    return 0;
}
static char *get_heredoc_filename(void)
{
    static int  count = 0;
    char        *num;
    char        *filename;

    num = ft_itoa(count++);
    filename = ft_strjoin("/tmp/.heredoc_", num);
    free(num);
    return (filename);
}



// Exécute tous les here_docs et retourne le fd du dernier
static int process_all_heredocs(t_redir **redirs)
{
    int     i;
    int     last_fd;
    char    *filename;
    char    *line;
    int     fd;

    i = 0;
    last_fd = -1;
    while (redirs[i])
    {
        if (redirs[i]->type == HERE_DOC)
        {
            // Si on avait un fd précédent, on le ferme
            if (last_fd != -1)
            {
                close(last_fd);
                last_fd = -1;
            }
            
            filename = get_heredoc_filename();
            fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0)
            {
                free(filename);
                return (-1);
            }
            while (1)
            {
                ft_putstr_fd("> ", 1);
                line = get_next_line(STDIN_FILENO);
                if (!line)
                    break;
                if (ft_strncmp(line, redirs[i]->file, ft_strlen(redirs[i]->file)) == 0 &&
                    line[ft_strlen(redirs[i]->file)] == '\n')
                {
                    free(line);
                    break;
                }
                ft_putstr_fd(line, fd);
                free(line);
            }
            close(fd);
            
            // On ouvre le fichier en lecture
            last_fd = open(filename, O_RDONLY);
            unlink(filename);
            free(filename);
            if (last_fd < 0)
                return (-1);
        }
        i++;
    }
    return (last_fd);
}

static int create_output_files(t_redir **redirs)
{
    int     i;
    int     fd;

    i = 0;
    while (redirs[i])
    {
        if (redirs[i]->type == REDIROUT || redirs[i]->type == APPEND)
        {
            fd = open(redirs[i]->file, O_WRONLY | O_CREAT, 0644);
            if (fd < 0)
                return (print_file_error(redirs[i]->file, strerror(errno)));
            close(fd);
        }
        i++;
    }
    return (0);
}

int    handle_input_redir(char *file, t_exec_data *exec)
{
    int    fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (print_file_error(file, strerror(errno)));
    exec->stdin_backup = fd;
    if (dup2(fd, STDIN_FILENO) < 0)
    {
        close(fd);
        return (print_file_error(file, strerror(errno)));
    }
    close(fd);
    return (0);
}

int    handle_output_redir(char *file, int append, t_exec_data *exec)
{
    int    fd;
    int    flags;

    flags = O_WRONLY | O_CREAT;
    flags |= (append ? O_APPEND : O_TRUNC);
    fd = open(file, flags, 0644);
    if (fd < 0)
        return (print_file_error(file, strerror(errno)));
    exec->stdout_backup = fd;
    if (dup2(fd, STDOUT_FILENO) < 0)
    {
        close(fd);
        return (print_file_error(file, strerror(errno)));
    }
    close(fd);
    return (0);
}

int    handle_redirections(t_command *cmd, t_exec_data *exec)
{
    t_redir *last_in;
    t_redir *last_out;
    int     heredoc_fd;

    if (!cmd->redir)
        return (0);

    // Créer tous les fichiers de sortie d'abord
    if (create_output_files(cmd->redir) != 0)
        return (1);

    // Traiter tous les here_docs et obtenir le fd du dernier
    heredoc_fd = process_all_heredocs(cmd->redir);
    if (heredoc_fd == -1 && get_last_redir_of_type(cmd->redir, HERE_DOC))
        return (1);

    // Trouver les dernières redirections d'entrée et sortie
    last_in = get_last_redir_of_type(cmd->redir, REDIRIN);
    last_out = get_last_redir_of_type(cmd->redir, REDIROUT);

    // Gérer l'entrée (here_doc a priorité sur redirection d'entrée)
    if (heredoc_fd != -1)
    {
        if (dup2(heredoc_fd, STDIN_FILENO) < 0)
        {
            close(heredoc_fd);
            return (1);
        }
        close(heredoc_fd);
    }
    else if (last_in)
    {
        if (handle_input_redir(last_in->file, exec) != 0)
            return (1);
    }
    // Gérer la dernière redirection de sortie
    if (last_out)
    {
        if (handle_output_redir(last_out->file, last_out->type == APPEND, exec) != 0)
            return (1);
    }

    return (0);
}


