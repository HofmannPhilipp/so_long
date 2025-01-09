/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:21 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/09 11:14:54 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
#include "./minilibx/mlx.h"

char	**create_map(char *path);
int		check_file_extension(char *path, char *extension);
char	*read_all_lines(int fd);
void	validate_map(char **map);
int		check_for_valid_chars(char **map);
int		check_walls(char **map);
int		check_dimensions(char **map);
int		check_valid_amount_componens(char **map);
void	print_map(char **map);
void	handle_error(char *error_msg);

#endif