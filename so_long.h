/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/13 15:40:49 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
#include "./minilibx/mlx.h"

#ifdef __APPLE__
    #define KEY_W 13
    #define KEY_A 0
    #define KEY_S 1
    #define KEY_D 2
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

typedef struct s_map
{
	int			width;
	int			height;
	char		**grid;
	t_player	duck;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_map	map;
} t_data;



t_map	create_map(char *path);
void	check_file_extension(char *path, char *extension);
char	*read_all_lines(int fd);
void	validate_grid(char **map);
int		check_for_valid_chars(char **map);
int		check_walls(char **map);
int		check_dimensions(char **map);
int		check_valid_amount_componens(char **map);
int		render_map(void *param);
void	print_map(char **map);
void	set_map_dimensions(t_map *map);
void	set_player(t_map *map);
void	render_ground(t_data data);
void	render_items(t_data data);
int		move(int keycode, void *param);
void	update_map(t_map *map, int x, int y);
void	handle_error(char *error_msg);

#endif