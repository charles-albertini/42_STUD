#include "minishell.h"

static char	**create_env_array(t_env *env)
{
	t_env	*current;
	char	**env_array;
	int		size;
	int		i;
	char	*tmp;

	size = 0;
	current = env;
	while (current)
	{
		size++;
		current = current->next;
	}
	env_array = malloc(sizeof(char *) * (size + 1));
	if (!env_array)
		return (NULL);
	i = 0;
	current = env;
	while (current)
	{
		tmp = ft_strjoin(current->key, "=");
		env_array[i] = ft_strjoin(tmp, current->value);
		free(tmp);
		current = current->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

static char	*find_command_path(char *cmd, t_env *env)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;
	t_env	*path_env;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = env;
	while (path_env && ft_strcmp(path_env->key, "PATH") != 0)
		path_env = path_env->next;
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env->value, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, X_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

static void	execute_single_command(t_command *cmd, t_env *env)
{
	char	**env_array;
	char	*cmd_path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		env_array = create_env_array(env);
		cmd_path = find_command_path(cmd->args[0], env);
		if (!cmd_path)
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(cmd->args[0], 2);
			exit(127);
		}
		execve(cmd_path, cmd->args, env_array);
		free(cmd_path);
		free_array(env_array);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
}

static void	execute_pipeline(t_command *cmd, t_env *env)
{
	int			pipe_fd[2];
	pid_t		pid;
	t_command	*current;

	current = cmd;
	while (current && current->next)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[1]);
			execute_single_command(current, env);
			exit(1);
		}
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		current = current->next;
	}
	if (current)
		execute_single_command(current, env);
}

void	execute_commands(t_shell *shell)
{
	t_command	*current;
	int			pipe_count;

	current = shell->cmds;
	pipe_count = 0;
	while (current)
	{
		if (current->next)
			pipe_count++;
		current = current->next;
	}
	if (pipe_count > 0)
		execute_pipeline(shell->cmds, shell->env);
	else if (shell->cmds->builtin_value != NOT_BUILTIN)
		execute_builtin(shell->cmds, shell->env);
	else
		execute_single_command(shell->cmds, shell->env);
}

// Ce code implémente les fonctionnalités principales de l'exécution :

// create_env_array: Convertit notre liste chaînée d'environnement en tableau de chaînes pour execve
// find_command_path: Cherche le chemin complet d'une commande en utilisant PATH
// execute_single_command: Exécuter une commande unique
// execute_pipeline: Gère l'exécution des commandes avec tuyaux
// execute_commands: Point d'entrée principal qui détermine comment exécuter les commandes

// Il nous faut maintenant implémenter la gestion des redirections. Je vais créer une deuxième partie du code.

#include "minishell.h"

#define REDIR_IN 1
#define REDIR_OUT 2
#define REDIR_APPEND 3
#define HEREDOC 4

static int	handle_input_redirection(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

static int	handle_output_redirection(char *file, int append)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

static int	handle_heredoc(char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
		return (0);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, pipe_fd[1]);
		free(line);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	return (1);
}

int	handle_redirections(t_command *cmd)
{
	int	i;
	int	success;

	i = 0;
	success = 1;
	while (cmd->redir && cmd->redir[i])
	{
		if (cmd->redir[i]->type == REDIR_IN)
			success = handle_input_redirection(cmd->redir[i]->file);
		else if (cmd->redir[i]->type == REDIR_OUT)
			success = handle_output_redirection(cmd->redir[i]->file, 0);
		else if (cmd->redir[i]->type == REDIR_APPEND)
			success = handle_output_redirection(cmd->redir[i]->file, 1);
		else if (cmd->redir[i]->type == HEREDOC)
			success = handle_heredoc(cmd->redir[i]->file);
		if (!success)
			return (0);
		i++;
	}
	return (1);
}

// Ce code gère toutes les redirections demandées dans le sujet :

// <: Redirection d'entrée
// >: Redirection de sortie
// >>: Redirection de sortie en mode append
// <<: Hérédoc

// Pour utiliser ces fonctions, il faut modifier la fonction execute_single_commandpour gérer les redirections avant d'exécuter la commande. Voici la modification nécessaire :

static void	execute_single_command(t_command *cmd, t_env *env)
{
	char	**env_array;
	char	*cmd_path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (!handle_redirections(cmd))
			exit(1);
		if (cmd->builtin_value != NOT_BUILTIN)
		{
			execute_builtin(cmd, env);
			exit(g_exit_status);
		}
		env_array = create_env_array(env);
		cmd_path = find_command_path(cmd->args[0], env);
		if (!cmd_path)
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putendl_fd(cmd->args[0], 2);
			exit(127);
		}
		execve(cmd_path, cmd->args, env_array);
		free(cmd_path);
		free_array(env_array);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
	}
}

Pour compléter l'implémentation, il devrait :

Ajouter la variable globale pour le statut de sortie :

int	g_exit_status;

Créer un en-tête de fichier pour les redirections avec les définitions des macros :

#define REDIR_IN 1
#define REDIR_OUT 2
#define REDIR_APPEND 3
#define HEREDOC 4

Implémenter la fonction execute_builtinqui sera appelée pour les commandes internes.

#include "minishell.h"

int	g_exit_status;

static void	handle_sigint(int sig)
{
	(void)sig;
	g_exit_status = 130;
	write(STDERR_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

static void	setup_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	reset_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static int	process_command(t_shell *shell, char *line)
{
	char	**tokens;

	if (!line)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		return (0);
	}
	if (line[0] != '\0')
		add_history(line);
	tokens = tokenize(line, shell->env);
	if (!tokens)
	{
		free(line);
		return (1);
	}
	shell->cmds = parse_commands(tokens, shell->env);
	free_tokens(tokens);
	if (shell->cmds)
		execute_commands(shell);
	free_commands(shell->cmds);
	shell->cmds = NULL;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;
	char	*prompt;

	(void)argc;
	(void)argv;
	g_exit_status = 0;
	shell.env = init_env(envp);
	shell.cmds = NULL;
	setup_signals();
	setup_terminal();
	prompt = "\001\033[1;32m\002minishell$ \001\033[0m\002";
	while (1)
	{
		line = readline(prompt);
		if (!process_command(&shell, line))
			break ;
		free(line);
	}
	reset_terminal();
	free_env(shell.env);
	clear_history();
	return (g_exit_status);
}

#include "minishell.h"

static void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	g_exit_status = 130;
	write(STDERR_FILENO, "\n", 1);
	close(STDIN_FILENO);
}

void	setup_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	setup_signals_heredoc(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	setup_signals_parent(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_redir(t_redir **redir)
{
	int	i;

	if (!redir)
		return ;
	i = 0;
	while (redir[i])
	{
		free(redir[i]->file);
		free(redir[i]);
		i++;
	}
	free(redir);
}

void	free_command(t_command *cmd)
{
	if (!cmd)
		return ;
	free_array(cmd->args);
	free_redir(cmd->redir);
	free(cmd);
}

void	free_commands(t_command *cmd)
{
	t_command	*next;

	while (cmd)
	{
		next = cmd->next;
		free_command(cmd);
		cmd = next;
	}
}

// Ces implémentations couvrent :

// La gestion des signaux (SIGINT avec Ctrl+C et SIGQUIT avec Ctrl+)
// La configuration du terminal pour un meilleur affichage
// La boucle principale du shell
// La gestion des signaux spécifiques pour les processus enfants et l'heredoc
// Les fonctions de nettoyage de la mémoire

// Points importants à noter :

// g_exit_statusest utilisé pour stocker le statut de sortie de la dernière commande
// Les signaux sont gérés différemment selon le contexte (shell interactif, commande en cours, heredoc)
// Le terminal est configuré pour ne pas afficher ^C lorsque Ctrl+C est enfoncé
// Le prompt est coloré en vert pour une meilleure lisibilité
// L'historique des commandes est géré avec add_history()

// Pour utiliser ce code, il faut s'assurer d'avoir toutes les fonctions auxiliaires nécessaires, notamment :

// init_env
// parse_commands
// tokenize
// Les fonctions de la libft

#include "minishell.h"

static t_builtin	get_builtin_type(char *cmd)
{
	if (!cmd)
		return (NOT_BUILTIN);
	if (ft_strcmp(cmd, "echo") == 0)
		return (ECHO);
	if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (PWD);
	if (ft_strcmp(cmd, "export") == 0)
		return (EXPORT);
	if (ft_strcmp(cmd, "unset") == 0)
		return (UNSET);
	if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	if (ft_strcmp(cmd, "exit") == 0)
		return (EXIT);
	return (NOT_BUILTIN);
}

void	execute_builtin(t_command *cmd, t_env *env)
{
	if (cmd->builtin_value == ECHO)
		g_exit_status = ft_echo(cmd->args);
	else if (cmd->builtin_value == CD)
		g_exit_status = ft_cd(cmd->args, env);
	else if (cmd->builtin_value == PWD)
		g_exit_status = ft_pwd();
	else if (cmd->builtin_value == EXPORT)
		g_exit_status = ft_export(cmd->args, env);
	else if (cmd->builtin_value == UNSET)
		g_exit_status = ft_unset(cmd->args, env);
	else if (cmd->builtin_value == ENV)
		g_exit_status = ft_env(env);
	else if (cmd->builtin_value == EXIT)
		g_exit_status = ft_exit(cmd->args);
}

int	is_builtin(t_command *cmd)
{
	cmd->builtin_value = get_builtin_type(cmd->args[0]);
	return (cmd->builtin_value != NOT_BUILTIN);
}

// Maintenant, implémentons chaque build séparément. Commençons par echo, pwd et env qui sont les plus simples :


#include "minishell.h"

int	ft_echo(char **args)
{
	int	i;
	int	n_option;

	n_option = 0;
	i = 1;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n_option = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!n_option)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("minishell: pwd: error retrieving current directory\n",
			STDERR_FILENO);
		return (1);
	}
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}

int	ft_env(t_env *env)
{
	t_env	*current;

	current = env;
	while (current)
	{
		if (current->value)
		{
			ft_putstr_fd(current->key, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putendl_fd(current->value, STDOUT_FILENO);
		}
		current = current->next;
	}
	return (0);
}

// Maintenant, implémentons les buildins plus complexes comme cd, export et unset :

#include "minishell.h"

static void	update_pwd(t_env *env)
{
	char	*old_pwd;
	char	*current_pwd;
	t_env	*pwd_var;
	t_env	*oldpwd_var;

	pwd_var = env;
	oldpwd_var = env;
	while (pwd_var && ft_strcmp(pwd_var->key, "PWD") != 0)
		pwd_var = pwd_var->next;
	while (oldpwd_var && ft_strcmp(oldpwd_var->key, "OLDPWD") != 0)
		oldpwd_var = oldpwd_var->next;
	if (pwd_var)
		old_pwd = ft_strdup(pwd_var->value);
	else
		old_pwd = NULL;
	current_pwd = getcwd(NULL, 0);
	if (pwd_var)
	{
		free(pwd_var->value);
		pwd_var->value = current_pwd;
	}
	if (oldpwd_var)
	{
		free(oldpwd_var->value);
		oldpwd_var->value = old_pwd;
	}
}

int	ft_cd(char **args, t_env *env)
{
	char	*path;
	int		ret;

	if (!args[1])
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (1);
		}
	}
	else
		path = args[1];
	ret = chdir(path);
	if (ret != 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		return (1);
	}
	update_pwd(env);
	return (0);
}

static t_env	*find_env_var(t_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	ft_export(char **args, t_env *env)
{
	int		i;
	char	*key;
	char	*value;
	t_env	*var;

	if (!args[1])
		return (ft_env(env));
	i = 1;
	while (args[i])
	{
		value = ft_strchr(args[i], '=');
		if (value)
		{
			*value = '\0';
			value++;
			key = args[i];
			var = find_env_var(env, key);
			if (var)
			{
				free(var->value);
				var->value = ft_strdup(value);
			}
			else
				ft_envlst_add_back(&env, ft_envlst_new(key, value));
		}
		i++;
	}
	return (0);
}

int	ft_unset(char **args, t_env *env)
{
	int		i;
	t_env	*current;
	t_env	*prev;

	i = 1;
	while (args[i])
	{
		current = env;
		prev = NULL;
		while (current)
		{
			if (ft_strcmp(current->key, args[i]) == 0)
			{
				if (prev)
					prev->next = current->next;
				free(current->key);
				free(current->value);
				free(current);
				break ;
			}
			prev = current;
			current = current->next;
		}
		i++;
	}
	return (0);
}

// Enfin, implémentons la commande exit :


#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **args)
{
	long	status;

	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args[1])
		exit(g_exit_status);
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(255);
	}
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	status = ft_atoi(args[1]);
	exit(status % 256);
}