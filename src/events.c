/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:54:30 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/21 16:37:08 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_keypress(mlx_key_data_t keycode, void *param)
{
	t_app *app;
	
	app = (t_app *)param;
	if (keycode.action != MLX_PRESS)
		return ;
	if (keycode.key == MLX_KEY_ESCAPE)
	{
		close_game(param);
		return ;
	}
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

void	close_game(void *param)
{
	t_app *app;
	
	app = (t_app *)param;
	mlx_close_window(app->mlx);
}