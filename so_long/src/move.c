/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:58 by calberti          #+#    #+#             */
/*   Updated: 2025/01/15 18:49:37 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32 - 1]
		[game->imag->chara->instances->x / 32] != MAP_WALL)
	{
		game->imag->chara->instances->y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		update_moves_display(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32 + 1] != MAP_WALL)
	{
		game->imag->chara->instances->x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		update_moves_display(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32 + 1]
		[game->imag->chara->instances->x / 32] != MAP_WALL)
	{
		game->imag->chara->instances->y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		update_moves_display(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32 - 1] != MAP_WALL)
	{
		game->imag->chara->instances->x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
		update_moves_display(game);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_up(game);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_right(game);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_down(game);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	collec_apple(game);
}
