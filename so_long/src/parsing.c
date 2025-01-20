/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:57:05 by calberti          #+#    #+#             */
/*   Updated: 2025/01/12 13:58:42 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_parsing(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("Error\nNeed two arg\n"), 1);
	if (check_extension(argv[1]) == 1)
		return (ft_printf("Error\nWrong extension\n"), 1);
	return (0);
}

int	ft_parsing_2(char **argv, t_game game)
{
	if (!game.map)
		return (ft_printf("Error\nEmpty map\n"), 1);
	if (check_map(game.map) == 1)
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (valid_path(&game, argv[1]) == 1)
		return (free_map(game.map), 1);
	return (0);
}
