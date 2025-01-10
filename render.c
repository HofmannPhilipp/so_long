/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/10 16:00:24 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map map)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		handle_error("failed to init");

	win_ptr = mlx_new_window(mlx_ptr, map.width * 50, map.height * 50, "Duck saves the world");
	if (!win_ptr)
		handle_error("failed to open window");

	render_ground(mlx_ptr, win_ptr, map);
	render_components(mlx_ptr, win_ptr, map);
	mlx_loop(mlx_ptr);
}

void	render_ground(void *mlx_ptr, void *win_ptr, t_map map)
{
	void	*bg_img_ptr;
	void	*wall_img_ptr;
	int		x;
	int		y;
	int		width;
	int		height;

	bg_img_ptr = mlx_png_file_to_image(mlx_ptr, "./img/grass.png", &width, &height);
	wall_img_ptr = mlx_png_file_to_image(mlx_ptr, "./img/wall.png", &width, &height);
	if (!bg_img_ptr)
		handle_error("could not load image");
	y = 0;
	while (y < (map.height))
	{
		x = 0;
		while (x < (map.width))
		{
			if (map.grid[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, wall_img_ptr, x * 50, y * 50);
			else
				mlx_put_image_to_window(mlx_ptr, win_ptr, bg_img_ptr, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	render_components(void *mlx_ptr, void *win_ptr, t_map map)
{
	void	*duck_img_ptr;
	void	*bread_img_ptr;
	void	*toilet_img_ptr;
	int		width;
	int		height;
	int		y;
	int		x;

	duck_img_ptr = mlx_png_file_to_image(mlx_ptr, "./img/duck.png", &width, &height);
	bread_img_ptr = mlx_png_file_to_image(mlx_ptr, "./img/food/bread.png", &width, &height);
	toilet_img_ptr = mlx_png_file_to_image(mlx_ptr, "./img/toilet.png", &width, &height);

	y = 0;
	while (y < (map.height))
	{
		x = 0;
		while (x < (map.width))
		{
			if (map.grid[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, duck_img_ptr, x * 50, y * 50);
			if (map.grid[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, toilet_img_ptr, x * 50, y * 50);
			if (map.grid[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, bread_img_ptr, x * 50, y * 50);
			x++;
		}
		y++;
	}
}