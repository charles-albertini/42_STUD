/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:43 by calberti          #+#    #+#             */
/*   Updated: 2025/01/15 19:14:33 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_game(t_game *game)
{
	game->move_count = 0;
	game->count_collec = 0;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", 1);
	if (!(game->mlx))
		return (ft_printf("Error\nError display\n"), 1);
	get_textures(game);
	get_images(game);
	draw_map(game, game->imag);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textu);
	free(game->imag);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (ft_parsing(argc, argv) == 1)
		return (1);
	game.map = read_map(argv[1]);
	if (ft_parsing_2(argv, game) == 1)
		return (1);
	size_map(&game, game.map);
	if (init_game(&game) == 1)
		return (1);
	return (0);
}
