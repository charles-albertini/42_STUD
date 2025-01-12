/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:50 by calberti          #+#    #+#             */
/*   Updated: 2025/01/12 22:32:02 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	size_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->n_collec = total_collec(game);
	game->map_width = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	game->map_height = i * 32;
}

int	check_extension(char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'r' || fn[i - 1] != 'e'
		|| fn[i - 2] != 'b'
		|| fn[i - 3] != '.')
		return (1);
	return (0);
}

char	*new_mapp(char *temp_map, int fd)
{
	char	*new_map;

	while (temp_map != NULL)
	{
		new_map = get_next_line(fd);
		if (new_map == NULL)
		{
			free(new_map);
			break ;
		}
		temp_map = ft_strjoin_gnl(temp_map, new_map);
		free(new_map);
	}
	return (temp_map);
}

char	**read_map(char *script_map)
{
	int		fd;
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
		return (0);
	temp_map = get_next_line(fd);
	temp_map = new_mapp(temp_map, fd);
	if (temp_map != NULL)
		map = ft_split(temp_map, '\n');
	else
		map = NULL;
	free(temp_map);
	close(fd);
	return (map);
}
