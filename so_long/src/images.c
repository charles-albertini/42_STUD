/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:37 by calberti          #+#    #+#             */
/*   Updated: 2025/01/13 17:45:43 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_moves_display(t_game *game)
{
	if (game->move)
		mlx_delete_image(game->mlx, game->move);
	game->move = mlx_put_string(game->mlx, ft_itoa(game->move_count), 10, 10);
}

void	get_textures(t_game *game)
{
	game->textu = malloc(sizeof(t_textures));
	game->textu->floor = mlx_load_png("textures/floor.png");
	game->textu->wall = mlx_load_png("textures/wall.png");
	game->textu->collec = mlx_load_png("textures/apple.png");
	game->textu->chara = mlx_load_png("textures/bob.png");
	game->textu->exit = mlx_load_png("textures/exit.png");
	game->textu->exit_2 = mlx_load_png("textures/exit2.png");
}

void	get_images(t_game *game)
{
	game->imag = malloc(sizeof(t_images));
	game->imag->floor = mlx_texture_to_image(game->mlx, game->textu->floor);
	game->imag->wall = mlx_texture_to_image(game->mlx, game->textu->wall);
	game->imag->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->imag->chara = mlx_texture_to_image(game->mlx, game->textu->chara);
	game->imag->exit = mlx_texture_to_image(game->mlx, game->textu->exit);
	game->imag->exit_2 = mlx_texture_to_image(game->mlx, game->textu->exit_2);
	mlx_delete_texture(game->textu->floor);
	mlx_delete_texture(game->textu->wall);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->chara);
	mlx_delete_texture(game->textu->exit);
	mlx_delete_texture(game->textu->exit_2);
}

void	draw_floor(t_game *game, t_images *image)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->floor, x * 32, y * 32);
			if (game->map[y][x] == MAP_WALL)
				mlx_image_to_window(game->mlx, image->wall, x * 32, y * 32);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, image->exit_2, x * 32, y * 32);
				mlx_image_to_window(game->mlx, image->exit, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game, t_images *image)
{
	int	x;
	int	y;

	draw_floor(game, image);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == MAP_COLLECTABLE)
				mlx_image_to_window(game->mlx, image->collec, x * 32, y * 32);
			if (game->map[y][x] == MAP_ENTRY)
				mlx_image_to_window(game->mlx, image->chara, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
