/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/24 14:08:09 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*victory_filter;
	mlx_image_t	*victory_text;
}				t_images;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_game
{
	int			width;
	int			height;
	int			moves;
	char		**map;
	t_player	player;
}				t_game;

typedef struct s_app
{
	mlx_t		*mlx;
	t_game		game;
	t_images	*images;
}				t_app;

//app
t_app			init_app(char *map_file);
t_images		*init_images(mlx_t *mlx);
mlx_image_t		*init_image(mlx_t *mlx, char *path);
void			free_images(mlx_t *mlx, t_images *images);
void			free_app(t_app app);

// map
char			**create_map(char *path);
void			set_map_size(t_game *game);
void			update_map(t_game *game, int x, int y);

// game
t_game			init_game_state(char *file);
int				is_exit_unlocked(t_game game);
int				is_game_finished(t_game game);
void			close_game(void *param);

// player
void			set_player(t_game *game);

// utils
char			*read_all_lines(int fd);
void			print_map(char **map);
void			handle_error(char *error_msg);
void			free_map(char **map);
int				count_component(char **map, char c);
char			**copy_map(t_game game);

// validation
void			validate_map(t_game game);
int				check_file_extension(char *path, char *extension);
int				check_for_valid_chars(char **map);
int				check_walls(char **map);
int				check_dimensions(char **map);
int				check_valid_amount_componens(char **map);
void			flood_fill(char **map, t_point coord, int *exit, \
					int *collectible);
int				check_valid_pathway(t_game game);

// render
void			render_map(void *param);
void			render_ground(t_app app);
void			render_items(t_app app);
void			render_victory_screen(t_app app);
int				render_image(t_app app, char c, int x, int y);

// events
void			resize_window(int width, int height, void *param);
void			handle_keypress(mlx_key_data_t keycode, void *param);

#endif