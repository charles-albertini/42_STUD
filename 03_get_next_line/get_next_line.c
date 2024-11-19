/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:06:04 by calberti          #+#    #+#             */
/*   Updated: 2024/11/18 22:40:52 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*temp;
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc (BUFFER_SIZE + 1);
	if (temp == NULL)
	{
		free(temp);
		return (NULL);
	}
	while (1)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (NULL);
		}
		if (bytes_read == 0 && (!buffer || !*buffer))
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (buffer == NULL)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n') || bytes_read == 0)
			break ;
	}
	free(temp);
	line = get_line_from_buffer(&buffer);
	if (!line)
		return (NULL);
	return (line);
}

/*
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
	fd = 0; //0 est l'entre standard, on lance ./prog et apres on tape un mot
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
*/
