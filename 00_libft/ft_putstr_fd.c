#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	int i = 0;

	while (s[i])
	{
		write(fd, &s[i], 1);
		i ++;
	}
	
}


int	main(int argc, char **argv)
{
    int fd = open ("test.txt", O_WRONLY | O_CREAT, 0644);
	if (argc == 2)
	{
		ft_putstr_fd(argv[1], fd);
	}
	return (0);
}
//0644 lire/ecrire par le proprio et lire pour les autres
//0 entre standard
//1 sortie standard
//2 sortie d'erreur
//3, 4, 5... les fichier qui seront succesivement ouvert
