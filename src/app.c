/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:33:45 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/22 08:45:04 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_app	init_app(char *map_file)
{
	t_app	app;

	app.game = init_game_state(map_file);
	validate_map(app.game);
	app.mlx = mlx_init(app.game.width * 50, app.game.height * 50,
			"Duck saves the world", false);
	if (!app.mlx)
	{
		free_map(app.game.map);
		handle_error("Error\nFailed to init mlx");
	}
	app.images = init_images(app.mlx);
	if (!app.images)
	{
		free_app(app);
		handle_error("Error\nFailed to init images");
	}
	return (app);
}

mlx_image_t	*init_image(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (NULL);
	return (image);
}

t_images	*init_images(mlx_t *mlx)
{
	t_images	*images;

	images = malloc(sizeof(t_images));
	if (!images)
		return (NULL);
	images->ground = init_image(mlx, "./images/grass.png");
	images->wall = init_image(mlx, "./images/wall.png");
	images->player = init_image(mlx, "./images/duck.png");
	images->collectible = init_image(mlx, "./images/food/cookie.png");
	images->exit = init_image(mlx, "./images/toilet.png");
	images->victory = mlx_new_image(mlx, mlx->width, mlx->height);
	if (!images->ground || !images->wall || !images->player
		|| !images->collectible || !images->exit || !images->victory)
		return (NULL);
	return (images);
}

void	free_images(mlx_t *mlx, t_images *images)
{
	if (!images || !mlx)
		return ;
	mlx_delete_image(mlx, images->ground);
	mlx_delete_image(mlx, images->wall);
	mlx_delete_image(mlx, images->player);
	mlx_delete_image(mlx, images->collectible);
	mlx_delete_image(mlx, images->exit);
	mlx_delete_image(mlx, images->victory);
	free(images);
};
void	free_app(t_app app)
{
	free_map(app.game.map);
	free_images(app.mlx, app.images);
}
