#include"minishell.h"

int	exec_builtin(t_command *cmd, t_env *env, t_shell *shell)
{
	if (cmd->builtin_value == ECHO)
		shell->exit_status = ft_echo(cmd->argc, cmd->args);
	else if (cmd->builtin_value == CD)
		shell->exit_status = ft_cd(shell);
	else if (cmd->builtin_value == PWD)
		shell->exit_status = ft_pwd(env);
	// else if (cmd->builtin_value == EXPORT)
	// 	shell->exit_status = ft_export(cmd->args, env);
	// else if (cmd->builtin_value == UNSET)
	// 	shell->exit_status = ft_unset(env, cmd->args);
	else if (cmd->builtin_value == ENV)
		shell->exit_status = ft_env(env);
	else if (cmd->builtin_value == EXIT)
		shell->exit_status = ft_exit(cmd->argc, cmd->args, shell);
	return(shell->exit_status);
}

// export, unset, cd pas dans des fork