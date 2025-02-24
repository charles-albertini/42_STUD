/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:27:52 by calberti          #+#    #+#             */
/*   Updated: 2025/02/24 22:43:32 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig_received = 0;

int	exec_single_cmd(t_shell *shell, t_command *cmd, t_exec_data *exec)
{
	char	*cmd_path;

	if (!cmd->args || !cmd->args[0])
		return (0);
	backup_std_fds(exec);
	if (handle_redirections(cmd) != 0)
		return (restore_std_fds(exec), 1);
	if (is_builtin(cmd->args[0]) != NOT_BUILTIN)
	{
		if (cmd->next)
		{
			if (fork() == 0)
				exit(exec_builtin(cmd, shell->env, shell));
			return (restore_std_fds(exec), 0);
		}
		return (restore_std_fds(exec), exec_builtin(cmd, shell->env, shell));
	}
	cmd_path = find_command_path(cmd->args[0], get_path_dirs(exec->env_arr));
	if (!cmd_path)
		return (handle_cmd_not_found(cmd->args[0]), restore_std_fds(exec), 127);
	if (execve(cmd_path, cmd->args, exec->env_arr) == -1)
		return (free(cmd_path), print_exec_error(cmd->args[0],
				strerror(errno)), restore_std_fds(exec), 126);
	return (0);
}

void	init_exec_data(t_exec_data *exec, t_shell *shell)
{
	exec->env_arr = env_list_to_array(shell->env);
	exec->last_status = 0;
	exec->stdin_backup = -1;
	exec->stdout_backup = -1;
	g_sig_received = 1;
}

int	executor(t_shell *shell)
{
	t_exec_data	exec;
	t_command	*current;
	int			pipe_fds[2];
	int			prev_pipe_read;
	char		**heredoc_files;

	current = shell->cmds;
	init_exec_data(&exec, shell);
	heredoc_files = process_heredocs(shell->cmds);
	if (verif_heredoc(heredoc_files, current, shell) == 1)
		return (1);
	if ((is_builtin(current->args[0]) != NOT_BUILTIN) && cmd_size(current) == 1
		&& !current->next && cmd_size_redi(current) == 0)
	{
		rl_outstream = stderr;
		backup_std_fds(&exec);
		handle_redirections(current);
		exec_builtin(shell->cmds, shell->env, shell);
		restore_std_fds(&exec);
		cleanup_heredoc_files(heredoc_files);
		return (shell->exit_status);
	}
	prev_pipe_read = -1;
	while (current)
	{
		current->pid = pipe_fork(current, pipe_fds, heredoc_files);
		if (current->pid == 1)
			return (1);
		if (current->pid == 0)
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
		prev_pipe_read = update_pipe_read(prev_pipe_read, current, pipe_fds);
	}
	wait_all_children(shell);
	cleanup_heredoc_files(heredoc_files);
	g_sig_received = 0;
	return (shell->exit_status);
}
