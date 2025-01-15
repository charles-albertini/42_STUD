/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:56:25 by calberti          #+#    #+#             */
/*   Updated: 2025/01/15 18:49:22 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	total_collec(t_game *game)
{
	int	total;
	int	i;
	int	o;

	total = 0;
	i = 0;
	while (game->map[i])
	{
		o = 0;
		while (game->map[i][o])
		{
			if (game->map[i][o] == 'C')
				total++;
			o++;
		}
		i++;
	}
	return (total);
}

void	delete_apple(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_collec;
	while (i < count)
	{
		if (((game->imag->collec->instances[i].y
					== game->imag->chara->instances->y)
				&& (game->imag->collec->instances[i].x
					== game->imag->chara->instances->x))
			&& game->imag->collec->instances[i].enabled == true)
		{
			count--;
			game->imag->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	collec_apple(t_game *game)
{
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_COLLECTABLE)
	{
		delete_apple(game);
		game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] = MAP_FLOOR;
		game->count_collec++;
		if (game->count_collec == game->n_collec)
			game->imag->exit->instances->enabled = false;
	}
	if (game->map[game->imag->chara->instances->y / 32]
		[game->imag->chara->instances->x / 32] == MAP_EXIT)
	{
		if (game->count_collec == game->n_collec)
			mlx_close_window(game->mlx);
	}
}
