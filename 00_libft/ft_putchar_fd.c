#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putchar_fd(argv[1][0], atoi(argv[2]));
	}
	return (0);
}
//0 entre standard
//1 sortie standard
//2 sortie d'erreur
//3, 4, 5... les fichier qui seront succesivement ouvert
