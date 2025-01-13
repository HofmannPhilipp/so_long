/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:58:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/13 15:08:43 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	create_map(char *path)
{
	int		fd;
	char	*str;
	t_map	map;

	check_file_extension(path, ".ber");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(NULL);
	str = read_all_lines(fd);
	map.grid = ft_split(str, '\n');
	if (map.grid == NULL)
		handle_error("Failed ft_split in func crate_map");
	set_map_dimensions(&map);
	set_player(&map);
	return (map);
}

void	set_map_dimensions(t_map *map)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (map->grid[height] != NULL)
		height++;
	while(map->grid[0][width] != '\0')
		width++;
	map->height = height;
	map->width = width;
}

char	*read_all_lines(int fd)
{
	char	*curr_line;
	char	*combined_lines;
	char	*temp;

	combined_lines = ft_strdup("");
	if (combined_lines == NULL)
		handle_error("Malloc failed in func: read_line");
	while ((curr_line = get_next_line(fd)) != NULL)
	{
		temp = combined_lines;
		combined_lines = ft_strjoin(combined_lines, curr_line);
		free(temp);
		free(curr_line);
		if (combined_lines == NULL)
			handle_error("Malloc failed in func: read_line");
	}
	return (combined_lines);
}
void	set_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{

			if (map->grid[y][x] == 'P')
			{
				map->duck.x = x;
				map->duck.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}