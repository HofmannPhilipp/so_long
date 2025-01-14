/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:07:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/14 11:20:26 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game_state(char *file)
{
	t_game	game;

	game.map = create_map(file);
	set_map_size(&game);
	set_player(&game);
	game.moves = 0;
	return (game);
}

int	move(int keycode, void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	if (keycode == KEY_W)
		update_map(&(data->game), data->game.player.x, data->game.player.y - 1);
	if (keycode == KEY_S)
		update_map(&(data->game), data->game.player.x, data->game.player.y + 1);
	if (keycode == KEY_A)
		update_map(&(data->game), data->game.player.x - 1, data->game.player.y);
	if (keycode == KEY_D)
		update_map(&(data->game), data->game.player.x + 1, data->game.player.y);
	render_map(param);
	if (is_game_finished(data->game) == EXIT_SUCCESS)
		render_victory_screen(*data);
	return (0);
}

int	is_game_finished(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while(y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] == 'C' || game.map[y][x] == 'E')
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	is_exit_unlocked(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while(y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] == 'C')
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}