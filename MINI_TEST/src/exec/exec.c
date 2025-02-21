#include "minishell.h"


/*POUR GERER LE CAS OU IL Y A PLUSIEURS OUTPUT ET QU'IL FAUT PRENDRE LE DERNIER*/
// void    backup_std_fds(t_exec_data *exec)
// {
//     exec->stdin_backup = dup(STDIN_FILENO);
//     exec->stdout_backup = dup(STDOUT_FILENO);
// }

// void    restore_std_fds(t_exec_data *exec)
// {
//     dup2(exec->stdin_backup, STDIN_FILENO);
//     dup2(exec->stdout_backup, STDOUT_FILENO);
//     close(exec->stdin_backup);
//     close(exec->stdout_backup);
// }


int    exec_single_cmd(t_shell *shell, t_command *cmd, t_exec_data *exec)
{
    char    *cmd_path;
    char    **path_dirs;

    if (!cmd->args || !cmd->args[0])
		return (0);
    if (handle_redirections(cmd, exec) != 0)
        return (1);
    if (is_builtin(cmd->args[0]) != NOT_BUILTIN)
    {
        if (cmd->next) // Si le built-in est dans un pipeline, il faut le forker
        {
            if (fork() == 0)
            {
                exec_builtin(cmd, shell->env, shell);
                exit(shell->exit_status); // On sort du processus enfant
            }
            return (0); // On ne l'exécute pas dans le parent
        }
        return (exec_builtin(cmd, shell->env, shell));
    }
    path_dirs = get_path_dirs(exec->env_arr);
    cmd_path = find_command_path(cmd->args[0], path_dirs);
    if (!cmd_path)
    {
        handle_cmd_not_found(cmd->args[0]);
        return (127);
    }
    if (execve(cmd_path, cmd->args, exec->env_arr) == -1)
    {
        free(cmd_path);
        print_exec_error(cmd->args[0], strerror(errno));
        return (126);
    }
    return (0);
}

void    init_exec_data(t_exec_data *exec, t_shell *shell)
{
    exec->env_arr = env_list_to_array(shell->env);
    exec->last_status = 0;
    exec->stdin_backup = dup(STDIN_FILENO);
    exec->stdout_backup = dup(STDOUT_FILENO);
}

int    executor(t_shell *shell)
{
    t_exec_data exec;
    t_command   *current;
	t_command   *current2;
    int         pipe_fds[2];
    int         prev_pipe_read;


    // Traiter tous les here_doc avant l'exécution
    if (process_heredocs(shell) < 0)
    {
        ft_putendl_fd("minishell: heredoc error", 2);
        return 1;
    }
	current = shell->cmds;
	current2 = shell->cmds;
	int size = 0;
	while (current2!=NULL)
	{
		current2=current2->next;
		size++;
	}
	if ((is_builtin(current->args[0]) != NOT_BUILTIN) && size == 1 && !current->next)
	{
        rl_outstream = stderr;
		handle_redirections(current, &exec);
        exec_builtin(shell->cmds, shell->env, shell);
        dup2(exec.stdout_backup, STDOUT_FILENO);
        close(exec.stdout_backup);
        return (shell->exit_status);
	}
    init_exec_data(&exec, shell);
    
    prev_pipe_read = -1;
    while (current)
    {
        if (current->next && pipe(pipe_fds) < 0)
            return (print_file_error("pipe", strerror(errno)));
        exec.pid = fork();
        if (exec.pid < 0)
            return (print_file_error("fork", strerror(errno)));
        if (exec.pid == 0)
        {
            if (prev_pipe_read != -1)
            {
                dup2(prev_pipe_read, STDIN_FILENO);
                close(prev_pipe_read);
            }
            if (current->next)
            {
                close(pipe_fds[0]);
                dup2(pipe_fds[1], STDOUT_FILENO);
                close(pipe_fds[1]);
            }
            exit(exec_single_cmd(shell, current, &exec));
        }
        if (prev_pipe_read != -1)
            close(prev_pipe_read);
        if (current->next)
        {
            close(pipe_fds[1]);
            prev_pipe_read = pipe_fds[0];
        }
        current = current->next;
    }
    wait_all_children(shell, &exec);
    return (shell->exit_status);
}

