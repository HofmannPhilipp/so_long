/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:10:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/24 17:15:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, t_point coord, int *exit, int *collectible)
{
	if (map[coord.y][coord.x] == '1' || map[coord.y][coord.x] == 'X'
		|| map[coord.y][coord.x] == 'E')
	{
		if (map[coord.y][coord.x] == 'E')
			(*exit) = 1;
		return ;
	}
	if (map[coord.y][coord.x] == 'C')
		(*collectible)++;
	map[coord.y][coord.x] = 'X';
	flood_fill(map, (t_point){coord.x + 1, coord.y}, exit, collectible);
	flood_fill(map, (t_point){coord.x - 1, coord.y}, exit, collectible);
	flood_fill(map, (t_point){coord.x, coord.y + 1}, exit, collectible);
	flood_fill(map, (t_point){coord.x, coord.y - 1}, exit, collectible);
}
