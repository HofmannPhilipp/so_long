/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:07:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/13 15:42:05 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	move(int keycode, void *param)
{
	t_data *data = (t_data *)param;
	if (keycode == KEY_W)
	{
		ft_printf("W\n");
		print_map(data->map.grid);
		update_map(&(data->map), data->map.duck.x, data->map.duck.y - 1);
		render_map(param);
	}
	if (keycode == KEY_S)
	{
		ft_printf("S\n");
		print_map(data->map.grid);
		update_map(&(data->map), data->map.duck.x, data->map.duck.y + 1);
		render_map(param);
	}
	if (keycode == KEY_A)
	{
		ft_printf("S\n");
		print_map(data->map.grid);
		update_map(&(data->map), data->map.duck.x - 1, data->map.duck.y);
		render_map(param);
	}
	if (keycode == KEY_D)
	{
		ft_printf("S\n");
		print_map(data->map.grid);
		update_map(&(data->map), data->map.duck.x + 1, data->map.duck.y);
		render_map(param);
	}
	return (0);
}

void	update_map(t_map *map, int x, int y)
{
	if (map->grid[y][x] == '1')
		return ;
	map->grid[map->duck.y][map->duck.x] = '0';
	map->grid[y][x] = 'P';
	map->duck.y = y;
	map->duck.x = x;
}