/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/21 17:00:38 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(void *param)
{
	t_app *app;
	app = (t_app *)param;
	render_ground(*app);
	render_items(*app);
	if (is_game_finished(app->game) == EXIT_SUCCESS)
		render_victory_screen(*app);
}

void	render_ground(t_app app)
{
	int		x;
	int		y;

	y = 0;
	while (y < (app.game.height))
	{
		x = 0;
		while (x < (app.game.width))
		{
			if (app.game.map[y][x] == '1')
				mlx_image_to_window(app.mlx, app.images->wall, x * app.images->wall->width, y * app.images->wall->height);
			else
				mlx_image_to_window(app.mlx, app.images->ground, x * app.images->ground->width, y * app.images->ground->height);
			x++;
		}
		y++;
	}
}

void	render_items(t_app app)
{
	int		y;
	int		x;
	y = 0;
	while (y < (app.game.height))
	{
		x = 0;
		while (x < (app.game.width))
		{
			if (app.game.map[y][x] == 'P')
				mlx_image_to_window(app.mlx, app.images->player,x * app.images->player->width, y * app.images->player->height);
			if (app.game.map[y][x] == 'E')
				mlx_image_to_window(app.mlx, app.images->exit, x * app.images->exit->width, y * app.images->exit->height);
			if (app.game.map[y][x] == 'C')
				mlx_image_to_window(app.mlx, app.images->collectible, x * app.images->collectible->width, y * app.images->collectible->height);
			x++;
		}
		y++;
	}
}

void	render_victory_screen(t_app app)
{
	int			x;
	int			y;
	y = 0;
	while (y < app.mlx->height)
	{
		x = 0;
		while (x < app.mlx->width)
		{
			mlx_put_pixel(app.images->victory, x, y, 0xFF101010);
			x++;
		}
		y++;
	}
	mlx_image_to_window(app.mlx, app.images->victory, 0, 0);
	mlx_put_string(app.mlx, "Congratulations! You won!",app.mlx->width/ 2 - 100, app.mlx->height /2);
}
