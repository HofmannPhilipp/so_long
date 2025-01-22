/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:20:34 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/21 16:21:19 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_amount_componens(char **map)
{
	int	e_count;
	int	p_count;
	int	c_count;

	e_count = count_component(map, 'E');
	p_count = count_component(map, 'P');
	c_count = count_component(map, 'C');
	
	if (e_count > 1 || p_count > 1 || c_count < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_for_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || map[i + 1] == NULL) && map[i][j] != '1')
				return (EXIT_FAILURE);
			if ((j == 0 || map[i][j + 1] == '\0') && map[i][j] != '1')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_dimensions(char **map)
{
	size_t	width;
	size_t	height;
	
	width = ft_strlen(*map);
	height = 0;
	while (map[height] != NULL)
	{
		if (width != ft_strlen(map[height]))
			return (EXIT_FAILURE);
		height++;
	}
	if (height == width)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int	check_valid_pathway(t_game game)
{
	int		exit;
	int		collectible;
	char	**copy;

	exit = 0;
	collectible = 0;
	copy = copy_map(game);
	flood_fill(copy, (t_point){game.player.x, game.player.y}, &exit, &collectible);
	free_map(copy);
	if (exit != count_component(game.map, 'E') || collectible != count_component(game.map, 'C'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
