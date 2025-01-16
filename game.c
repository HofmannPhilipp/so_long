/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:07:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/16 10:44:48 by phhofman         ###   ########.fr       */
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

void	close_game(void *param)
{
	t_app *app;
	
	app = (t_app *)param;
	mlx_close_window(app->mlx);
	free_map(app->game.map);
}

void	handle_keypress(mlx_key_data_t keycode, void *param)
{
	t_app *app;
	
	app = (t_app *)param;
	if (keycode.action != MLX_PRESS)
		return ;
	if (keycode.key == MLX_KEY_ESCAPE)
		close_game(param);
	if (is_game_finished(app->game) == EXIT_SUCCESS)
		return ;
	if (keycode.key == MLX_KEY_W)
		update_map(&(app->game), app->game.player.x, app->game.player.y - 1);
	if (keycode.key == MLX_KEY_S)
		update_map(&(app->game), app->game.player.x, app->game.player.y + 1);
	if (keycode.key == MLX_KEY_A)
		update_map(&(app->game), app->game.player.x - 1, app->game.player.y);
	if (keycode.key == MLX_KEY_D)
		update_map(&(app->game), app->game.player.x + 1, app->game.player.y);
	render_map(param);
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
