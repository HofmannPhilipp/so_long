/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:58:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/21 16:44:04 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *path)
{
	int		fd;
	char	*str;
	char	**map;

	if (check_file_extension(path, ".ber") == EXIT_FAILURE)
		handle_error("Error\nFile extension must be .ber");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error("Error\nFailed to open file");
	str = read_all_lines(fd);
	close(fd);
	map= ft_split(str, '\n');
	free(str);
	if (map == NULL)
		handle_error("Failed ft_split in func create_map");
	return (map);
}

void	set_map_size(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (game->map[height] != NULL)
		height++;
	while(game->map[0][width] != '\0')
		width++;
	game->height = height;
	game->width = width;
}

void	update_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E' && is_exit_unlocked(*game) == EXIT_FAILURE)
		return ;
	game->map[game->player.y][game->player.x] = '0';
	game->map[y][x] = 'P';
	game->player.y = y;
	game->player.x = x;
	game->moves++;
	ft_printf("moves: %d\n", game->moves);
}
void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
