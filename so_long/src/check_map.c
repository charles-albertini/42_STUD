/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:31 by calberti          #+#    #+#             */
/*   Updated: 2025/01/12 14:04:01 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle_map(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (1);
		else
			i++;
	}
	return (0);
}

int	wrong_map(char **map)
{
	int	i;
	int	o;

	i = 0;
	while (map[i])
	{
		o = 0;
		while (map[i][o])
		{
			if (!(map[i][o] == MAP_EXIT || map[i][o] == MAP_ENTRY
				|| map[i][o] == MAP_WALL || map[i][o] == MAP_FLOOR
				|| (map[i][o] == MAP_COLLECTABLE)))
				return (1);
			else
				o++;
		}
		i++;
	}
	return (0);
}

int	wall_map(char **map)
{
	int	i;
	int	line;

	line = 0;
	i = 0;
	while (map[line])
		line++;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (1);
		i++;
	}
	line--;
	while (line > 0)
	{
		if (map[line][0] != '1' || map[line][ft_strlen(map[0]) - 1] != '1')
			return (1);
		line --;
	}
	return (0);
}

int	check_map(char **map)
{
	if (rectangle_map(map) == 1)
		return (ft_printf("Error\nNot a rectangle.\n"), 1);
	if (wrong_map(map) == 1)
		return (ft_printf("Error\nWrong or not enough components\n"), 1);
	if (wall_map(map) == 1)
		return (ft_printf("Error\nNeed walls\n"), 1);
	if (min_tiles(map) == 1)
		return (ft_printf("Error\nWrongs or not enough components\n"), 1);
	return (0);
}
