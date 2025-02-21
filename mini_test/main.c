#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>


//SIGNAUX

volatile sig_atomic_t	sig_received = 0;

void handle_sigint(int sig)
{
	(void)sig;
	if(sig_received == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		sig_received = 0;
	}
	else
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_shell	shell;
	t_token	**tokens;
	char	*line;
	struct sigaction	sa;

	//SIGNAUX
	signal(SIGINT, handle_sigint);
	rl_outstream = stderr;
	sa.sa_handler = handle_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);

	shell.env = init_env(envp);
	while (1)
	{
		
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		/* Tokenisation et traitement */
		tokens = take_ur_token_and_leave_me_alone(shell.env, line);
		if (!tokens)
		{
			free(line);
			continue ;
		}
		/* Parsing des tokens en commandes */
		
		shell.cmds = parse_tokens(tokens);
		/* Exécution des commandes */
		executor(&shell);
		/* Libération des ressources */
		free_tokens(tokens);
		free(line);
		/* Si besoin, libérez aussi la liste des commandes :
		   free_commands(shell.cmds); */
	}
	free(line);
	rl_clear_history();
	free_env(shell.env);
	return (0);
}

