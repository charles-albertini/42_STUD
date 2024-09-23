#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;
	
	i = 0;
	j = 0;
	if (!s1)
	    s1 = ""; //pour la premiere lecture, s1 est null on le remplace donc par un chaine vide
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (s1[0]) // si s1 n'est pas vide on le libere
	    free(s1);
	return (str);
}

// Fonction pour obtenir une ligne complète depuis le tampon
char *get_line_from_buffer(char **buffer) // **char pour modifier directement le pointeur dans la fonction appelant
{                                        // c'est un pointeur vers une adresse d'un pointeur
    char 	*line;
    char 	*new_buffer;
    int 	i;
    int 	j;

    line = NULL;
    i = 0;
    j = 0;
    // On cherche la fin de la ligne (délimitée par '\n' ou la fin de la chaîne)
    while ((*buffer)[i] && (*buffer)[i] != '\n')
	i++;

    // On alloue l'espace pour la ligne (incluant '\0')
    line = malloc(i + 2); // +1 pour '\0' et +1 pour '\n'
    if (!line)
	return NULL;

    // On copie les caractères jusqu'à '\n' ou la fin de la chaîne
    while (j < i) {
	line[j] = (*buffer)[j];
	j++;
    }

    // On ajoute '\n' s'il est présent
    if ((*buffer)[i] == '\n') {
	line[i] = '\n';
	i++;
    }

    line[i] = '\0'; // Terminaison de la chaîne

    // On met à jour le tampon pour retirer la ligne qu'on vient de lire
    new_buffer = malloc(ft_strlen(*buffer) - i + 1);
    if (!new_buffer)
	return NULL;

    j = 0;
    while ((*buffer)[i])
    {
	new_buffer[j] = (*buffer)[i]; //on met dans le nouveau buffer le reste de l'ancien buffer
	i++;
	j++;
    }
    new_buffer[j] = '\0';

    free(*buffer); // On libère l'ancien tampon
    *buffer = new_buffer;

    return line;
}
