/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/17 16:35:33 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "libft.h"
# include "MLX42.h"

typedef struct	s_point
{
	int x;
	int y;
} t_point;

typedef struct s_textures
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
} t_textures;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	char		**map;
	t_player	player;
}	t_game;

typedef struct s_app
{
	mlx_t		*mlx;
	t_game		game;
	t_textures	*textures;
} t_app;

//app
t_app		init_app(char *map_file);
t_textures	*init_textures(void *mlx);
mlx_image_t	*init_image(void *mlx, char *path);
void		free_textures(void *mlx, t_textures *textures);
void		free_app(t_app app);

// map
char		**create_map(char *path);
void		set_map_size(t_game *game);
void		update_map(t_game *game, int x, int y);

// game
t_game		init_game_state(char *file);
void		handle_keypress(mlx_key_data_t keycode, void *param);
int			is_exit_unlocked(t_game game);
int			is_game_finished(t_game game);
void		close_game(void *param);

// player
void		set_player(t_game *game);

// utils
char		*read_all_lines(int fd);
void		print_map(char **map);
void		handle_error(char *error_msg);
void		free_map(char **map);
mlx_image_t	*init_image(void *mlx, char *path);
int			count_component(char **map, char c);

// validation
void		validate_map(t_game game);
int			check_file_extension(char *path, char *extension);
int			check_for_valid_chars(char **map);
int			check_walls(char **map);
int			check_dimensions(char **map);
int			check_valid_amount_componens(char **map);
void		flood_fill(char **map, t_point coord, int *exit, int *collectible);
int			check_valid_pathway(t_game game);
char		**copy_map(t_game game);
// render
void		render_map(void	*param);
void		render_ground(t_app app);
void		render_items(t_app app);
void		render_victory_screen(t_app app);

#endif