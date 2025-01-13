/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:57:18 by calberti          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:52 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <stdint.h>

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLECTABLE 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'

# define BUFFER_SIZE 50
# define MOVE		32

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*chara;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit_2;
}				t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collec;
	mlx_image_t	*chara;
	mlx_image_t	*exit;
	mlx_image_t	*exit_2;
}				t_images;

typedef struct s_game
{
	struct s_textures	*textu;
	struct s_images		*imag;
	mlx_t				*mlx;
	char				**map;
	int					map_width;
	int					map_height;
	int					count_collec;
	int					move_count;
	int					n_collec;
	mlx_image_t			*move;
	char				**map_2;
}						t_game;

int		init_game(t_game *game);
int		ft_parsing(int argc, char **argv);
int		ft_parsing_2(char **argv, t_game game);
int		check_extension(char *fn);
char	**read_map(char *map);
int		check_map(char **map);
int		rectangle_map(char **map);
int		wrong_map(char **map);
int		wall_map(char **map);
void	size_map(t_game *game, char **map);
int		valid_path(t_game *game, char *fd);
int		*start_pos(char **map);
void	flood_map(t_game *game, int x, int y);
int		check_flood(char **map);
int		total_collec(t_game *game);
void	free_map(char **map);
int		min_tiles(char **map);
void	update_moves_display(t_game *game);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	draw_map(t_game *game, t_images *image);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	collec_orbs(t_game *game);
void	delete_orbs(t_game *game);

#endif