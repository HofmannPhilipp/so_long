/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/10 16:00:14 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
#include "./minilibx/mlx.h"

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}	t_map;

t_map	create_map(char *path);
void	check_file_extension(char *path, char *extension);
char	*read_all_lines(int fd);
void	validate_grid(char **map);
int		check_for_valid_chars(char **map);
int		check_walls(char **map);
int		check_dimensions(char **map);
int		check_valid_amount_componens(char **map);
void	render_map(t_map map);
void	print_map(char **map);
void	set_map_dimensions(t_map *map);
void	render_ground(void *mlx_ptr, void *win_ptr, t_map map);
void	render_components(void *mlx_ptr, void *win_ptr, t_map map);
void	handle_error(char *error_msg);

#endif