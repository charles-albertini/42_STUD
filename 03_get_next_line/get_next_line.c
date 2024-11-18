#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *temp = malloc (BUFFER_SIZE + 1); // on declare temp avec malloc pour gerer BUFF_SIZE = 10000000
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
	return (NULL);

    while (1) {
	// Lecture dans le fichier
	int bytes_read = read(fd, temp, BUFFER_SIZE); // on lit fd, on stock dans temp et lit on lit BUFFER_SIZE octet
	if (bytes_read < 0)
	    return NULL; // Erreur de lecture
	if (bytes_read == 0 && (!buffer || !*buffer)) // !buffer verifie si le poiteur buffer est null
	{                                            //  !*buffer verifie si le contenue poiter par buffer est vide
	    free(buffer);
	    return NULL; // Fin du fichier et plus rien dans le buffer
	}

	temp[bytes_read] = '\0';
	buffer = ft_strjoin(buffer, temp);
	if (buffer == NULL)
	    return NULL;

	line = get_line_from_buffer(&buffer);
	if (line == NULL)
	    return (NULL);
	else
	    return line;
	
    }
}

#include <stdio.h>
int main(int argc, char *argv[])
{
    
    int		fd;
    char	*line;
    int		nb;
    int		nb_read;
   
    if (argc == 2) // si on a donner un fichier
    {
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	    return 1;
    }
    if (argc == 1) // si y a pas de fichier
	fd = 0; // on met fd a 0, 0 est l'entre standard, on lance ./prog et apres on tape un mot
    nb = 0;
    nb_read = 40; //nombre de ligne a lire 
    
    while (nb < nb_read)
    {
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	if (line == NULL)
	    break;
	nb++;
    }
    close(fd);
    return 0;
}

