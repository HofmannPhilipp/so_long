/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:47:46 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/13 14:50:57 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_map(void *param)
{
	t_data *data = (t_data *)param;
	render_ground(*data);
	render_items(*data);
	return (0);
}

void	render_ground(t_data data)
{
	void	*bg_img_ptr;
	void	*wall_img_ptr;
	int		x;
	int		y;
	int		width;
	int		height;

	bg_img_ptr = mlx_png_file_to_image(data.mlx, "./img/grass.png", &width, &height);
	wall_img_ptr = mlx_png_file_to_image(data.mlx, "./img/wall.png", &width, &height);
	if (!bg_img_ptr)
		handle_error("could not load image");
	y = 0;
	while (y < (data.map.height))
	{
		x = 0;
		while (x < (data.map.width))
		{
			if (data.map.grid[y][x] == '1')
				mlx_put_image_to_window(data.mlx, data.window, wall_img_ptr, x * 50, y * 50);
			else
				mlx_put_image_to_window(data.mlx, data.window, bg_img_ptr, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	render_items(t_data data)
{
	void	*duck;
	void	*bread;
	void	*toilet;
	int		width;
	int		height;
	int		y;
	int		x;

	duck = mlx_png_file_to_image(data.mlx, "./img/duck.png", &width, &height);
	bread = mlx_png_file_to_image(data.mlx, "./img/food/bread.png", &width, &height);
	toilet = mlx_png_file_to_image(data.mlx, "./img/toilet.png", &width, &height);
	y = 0;
	while (y < (data.map.height))
	{
		x = 0;
		while (x < (data.map.width))
		{
			if (data.map.grid[y][x] == 'P')
				mlx_put_image_to_window(data.mlx, data.window, duck, x * 50, y * 50);
			if (data.map.grid[y][x] == 'E')
				mlx_put_image_to_window(data.mlx, data.window, toilet, x * 50, y * 50);
			if (data.map.grid[y][x] == 'C')
				mlx_put_image_to_window(data.mlx, data.window, bread, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
