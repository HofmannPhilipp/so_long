/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/15 16:38:01 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
# include "MLX42/MLX42.h"

#ifdef __APPLE__
    #define KEY_W 13
    #define KEY_A 0
    #define KEY_S 1
    #define KEY_D 2
	#define KEY_ESC 53
#elif __linux__
    #define KEY_W 119
    #define KEY_A 97
    #define KEY_S 115
    #define KEY_D 100
#endif

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	int			width;
	int			height;
	int			game_state;
	int			moves;
	char		**map;
	t_player	player;
}	t_game;

typedef struct s_data
{
	mlx_t	*mlx;
	t_game	game;
} t_data;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
} t_img;

// map
char	**create_map(char *path);
void	set_map_size(t_game *game);
// void	update_map(t_game *game, int x, int y);

// game
t_game	init_game_state(char *file);
void	handle_keypress(mlx_key_data_t keycode, void *param);
// int		is_exit_unlocked(t_game game);
// int		is_game_finished(t_game game);
void		close_game(void *param);

// player
void	set_player(t_game *game);


// utils
char	*read_all_lines(int fd);
void	print_map(char **map);
void	handle_error(char *error_msg);
void	free_map(char **map);
// t_img	init_img(void *mlx, char *path);

// validation
// void	check_file_extension(char *path, char *extension);
// void	validate_grid(char **map);
// int		check_for_valid_chars(char **map);
// int		check_walls(char **map);
// int		check_dimensions(char **map);
// int		check_valid_amount_componens(char **map);

// render
void	render_map(void	*param);
void	render_ground(t_data data);
// void	render_items(t_data data);
// void	render_victory_screen(t_data data);

#endif