/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:38 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	render_ground(*app);
	render_items(*app);
	if (is_game_finished(app->game) == EXIT_SUCCESS)
		render_victory_screen(*app);
}

void	render_ground(t_app app)
{
	int	error_flag;
	int	y;
	int	x;

	error_flag = 0;
	y = 0;
	while (y < (app.game.height))
	{
		x = 0;
		while (x < (app.game.width))
		{
			if (render_image(app, app.game.map[y][x], x, y) < 0)
			{
				handle_error("Error\n In render_items: mlx_image_to_window failed\n");
				free_app(app);
			}
			x++;
		}
		y++;
	}
}

void	render_items(t_app app)
{
	int	error_flag;
	int	y;
	int	x;

	error_flag = 0;
	y = 0;
	while (y < (app.game.height))
	{
		x = 0;
		while (x < (app.game.width))
		{
			if (render_image(app, '0', x, y) < 0)
			{
				handle_error("Error\n In render_items: mlx_image_to_window failed\n");
				free_app(app);
			}
			if (render_image(app, app.game.map[y][x], x, y) < 0)
			{
				handle_error("Error\n In render_items: mlx_image_to_window failed\n");
				free_app(app);
			}
			x++;
		}
		y++;
	}
}

void	render_victory_screen(t_app app)
{
	int	x;
	int	y;

	y = 0;
	while (y < app.mlx->height)
	{
		x = 0;
		while (x < app.mlx->width)
		{
			mlx_put_pixel(app.images->victory_filter, x, y, 0xFF101010);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(app.mlx, app.images->victory_filter, 0, 0) < 0)
	{
		free_app(app);
		handle_error("Error\n In render_victory_screen: mlx_image_to_window failed\n");
	}
	app.images->victory_text = mlx_put_string(app.mlx, "Congratulations! You won!", \
		app.mlx->width / 2 - 100, app.mlx->height / 2);
	
}
int	render_image(t_app app, char c, int x, int y)
{
	if (c == '1')
		return (mlx_image_to_window(app.mlx, app.images->wall, x * app.images->wall->width, y * app.images->wall->height));
	if (c == '0')
		return (mlx_image_to_window(app.mlx, app.images->ground, x * app.images->ground->width, y * app.images->ground->height));
	if (c == 'P')
		return (mlx_image_to_window(app.mlx, app.images->player, x * app.images->player->width, y * app.images->player->height));
	if (c == 'E')
		return (mlx_image_to_window(app.mlx, app.images->exit, x * app.images->exit->width, y * app.images->exit->height));
	if (c == 'C')
		return (mlx_image_to_window(app.mlx, app.images->collectible, x * app.images->collectible->width, y * app.images->collectible->height));
	return (-1);
}
