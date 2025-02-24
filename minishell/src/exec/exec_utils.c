/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:25:13 by calberti          #+#    #+#             */
/*   Updated: 2025/02/24 22:11:30 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (NOT_BUILTIN);
	if (!ft_strcmp(cmd, "echo"))
		return (ECHO);
	if (!ft_strcmp(cmd, "cd"))
		return (CD);
	if (!ft_strcmp(cmd, "pwd"))
		return (PWD);
	if (!ft_strcmp(cmd, "export"))
		return (EXPORT);
	if (!ft_strcmp(cmd, "unset"))
		return (UNSET);
	if (!ft_strcmp(cmd, "env"))
		return (ENV);
	if (!ft_strcmp(cmd, "exit"))
		return (EXIT);
	return (NOT_BUILTIN);
}

void	wait_all_children(t_shell *shell)
{
	t_command	*cmd;
	int			status;

	cmd = shell->cmds;
	while (cmd)
	{
		if (cmd->pid > 0)
		{
			waitpid(cmd->pid, &status, 0);
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
		}
		cmd = cmd->next;
	}
}

void	backup_std_fds(t_exec_data *exec)
{
	exec->stdin_backup = dup(STDIN_FILENO);
	exec->stdout_backup = dup(STDOUT_FILENO);
}

void	restore_std_fds(t_exec_data *exec)
{
	if (exec->stdin_backup != -1)
	{
		dup2(exec->stdin_backup, STDIN_FILENO);
		close(exec->stdin_backup);
		exec->stdin_backup = -1;
	}
	if (exec->stdout_backup != -1)
	{
		dup2(exec->stdout_backup, STDOUT_FILENO);
		close(exec->stdout_backup);
		exec->stdout_backup = -1;
	}
}

void	cleanup_heredoc_files(char **heredoc_files)
{
	int	i;

	if (!heredoc_files)
		return ;
	i = 0;
	while (heredoc_files[i])
	{
		unlink(heredoc_files[i]);
		free(heredoc_files[i]);
		i++;
	}
	free(heredoc_files);
}
