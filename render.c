/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/15 16:56:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(void *param)
{
	t_data *data;
	
	data = (t_data *)param;
	render_ground(*data);
	// render_items(*data);
	// if (is_game_finished(data->game) == EXIT_SUCCESS)
	// 	render_victory_screen(*data);
}

void	render_ground(t_data data)
{
	mlx_texture_t	*grass_texture;
	mlx_texture_t	*wall_texture;
	int		x;
	int		y;

	grass_texture = mlx_load_png("./img/grass.png");
	wall_texture = mlx_load_png("./img/wall.png");

	mlx_image_t *grass = mlx_texture_to_image(data.mlx, grass_texture);
	mlx_image_t *wall = mlx_texture_to_image(data.mlx, wall_texture);
	y = 0;
	while (y < (data.game.height))
	{
		x = 0;
		while (x < (data.game.width))
		{
			if (data.game.map[y][x] == '1')
			mlx_image_to_window(data.mlx, wall, x * wall->width, y * wall->height);
			else
			mlx_image_to_window(data.mlx, grass, x * grass->width, y * grass->height);
			x++;
		}
		y++;
	}
	// mlx_destroy_image(data.mlx, grass.img);
	// mlx_destroy_image(data.mlx, wall.img);
}

// void	render_items(t_data data)
// {
// 	t_img	duck;
// 	t_img	cookie;
// 	t_img	toilet;
// 	int		y;
// 	int		x;

// 	duck = init_img(data.mlx, "./img/duck.png");
// 	cookie = init_img(data.mlx, "./img/food/cookie.png");
// 	toilet = init_img(data.mlx, "./img/toilet.png");
// 	y = 0;
// 	while (y < (data.game.height))
// 	{
// 		x = 0;
// 		while (x < (data.game.width))
// 		{
// 			if (data.game.map[y][x] == 'P')
// 				mlx_put_image_to_window(data.mlx, data.window, duck.img, x * duck.width, y * duck.height);
// 			if (data.game.map[y][x] == 'E')
// 				mlx_put_image_to_window(data.mlx, data.window, toilet.img, x * toilet.width, y * toilet.height);
// 			if (data.game.map[y][x] == 'C')
// 				mlx_put_image_to_window(data.mlx, data.window, cookie.img, x * cookie.width, y * cookie.height);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_destroy_image(data.mlx, duck.img);
// 	mlx_destroy_image(data.mlx, cookie.img);
// 	mlx_destroy_image(data.mlx, toilet.img);
// }

// void	render_victory_screen(t_data data)
// {
// 	mlx_string_put(data.mlx, data.window, 50, 50, 0x00FF0000, "Congratulations! You won!");
// }
