/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 22:06:32 by calberti          #+#    #+#             */
/*   Updated: 2024/12/06 16:09:48 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*s1_null(char *s1)
{
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	s1 = s1_null(s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
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
	free(s1);
	return (str);
}

char	*ft_new_buffer(char **buffer, int i)
{
	int		j;
	char	*new_buffer;

	j = 0;
	new_buffer = malloc(ft_strlen(*buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while ((*buffer)[i])
	{
		new_buffer[j] = (*buffer)[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';
	free(*buffer);
	return (new_buffer);
}

char	*get_line_from_buffer(char **buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*buffer) || !(*buffer)[0])
		return (NULL);
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = (*buffer)[j];
		j++;
	}
	if ((*buffer)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	*buffer = ft_new_buffer(buffer, i);
	return (line);
}
