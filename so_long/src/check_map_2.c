/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:10 by calberti          #+#    #+#             */
/*   Updated: 2025/01/12 21:42:36 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	min_tiles(char **map)
{
	int	i;
	int	o;
	int	n_exit_char;
	int	n_collec;

	i = 0;
	n_exit_char = 0;
	n_collec = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (map[i][o] == MAP_EXIT || map[i][o] == MAP_ENTRY)
				n_exit_char++;
			if (map[i][o] == MAP_COLLECTABLE)
				n_collec++;
			o++;
		}
		i++;
	}
	if (n_exit_char != 2 || n_collec < 1)
		return (1);
	return (0);
}

int	*start_pos(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == MAP_ENTRY)
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	flood_map(t_game *game, int y, int x)
{
	if (!(x < 1 || y < 1 || x >= game->map_width || y > game->map_height
			|| game->map_2[y][x] == '1' || game->map_2[y][x] == 'X'))
	{
		game->map_2[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y - 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y, x - 1);
	}
}

int	check_flood(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == MAP_WALL || map[i][o] == 'X'
				|| map[i][o] == MAP_FLOOR))
				return (1);
			o++;
		}
		i++;
	}
	return (0);
}

int	valid_path(t_game *game, char *fd)
{
	int	*pos;

	game->map_2 = read_map(fd);
	pos = start_pos(game->map_2);
	flood_map(game, pos[0], pos[1]);
	if (check_flood(game->map_2) == 1)
	{
		free(pos);
		free_map(game->map_2);
		return (ft_printf("Error\nNo path\n"), 1);
	}
	free(pos);
	free_map(game->map_2);
	return (0);
}
