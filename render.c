/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/17 12:04:35 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(void *param)
{
	t_app *app;
	app = (t_app *)param;
	free_textures(app->mlx, app->textures);
	app->textures = init_textures(app->mlx);
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
			mlx_image_to_window(app.mlx, app.textures->wall, x * app.textures->wall->width, y * app.textures->wall->height);
			else
			mlx_image_to_window(app.mlx, app.textures->ground, x * app.textures->ground->width, y * app.textures->ground->height);
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
				mlx_image_to_window(app.mlx, app.textures->player,x * app.textures->player->width, y * app.textures->player->height);
			if (app.game.map[y][x] == 'E')
				mlx_image_to_window(app.mlx, app.textures->exit, x * app.textures->exit->width, y * app.textures->exit->height);
			if (app.game.map[y][x] == 'C')
				mlx_image_to_window(app.mlx, app.textures->collectible, x * app.textures->collectible->width, y * app.textures->collectible->height);
			x++;
		}
		y++;
	}
}

void	render_victory_screen(t_app app)
{
	mlx_put_string(app.mlx, "Congratulations! You won!",50, 50);
}
