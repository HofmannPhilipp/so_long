/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:33:45 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/17 16:23:26 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_app	init_app(char *map_file)
{
	t_app	app;

	app.game = init_game_state(map_file);
	validate_map(app.game);
	app.mlx = mlx_init(app.game.width * 50, app.game.height * 50, "Duck saves the world", true);
	if (!app.mlx)
	{
		free_app(app);
		handle_error("Error\nFailed to init mlx");
	}
	app.textures = init_textures(app.mlx);
	if (!app.textures)
	{
		free_app(app);
		handle_error("Error\nFailed to init textures");
	}
	return (app);
}

mlx_image_t	*init_image(void *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	return (image);
}

t_textures	*init_textures(void *mlx)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->ground = init_image(mlx, "./textures/grass.png");
	textures->wall = init_image(mlx, "./textures/wall.png");
	textures->player = init_image(mlx, "./textures/duck.png");
	textures->collectible = init_image(mlx, "./textures/food/cookie.png");
	textures->exit = init_image(mlx, "./textures/toilet.png");
	if (!textures->ground || !textures->wall || !textures->player || !textures->collectible || !textures->exit)
		return (NULL);
	return (textures);
}

void	free_textures(void *mlx, t_textures *textures)
{
	if (!textures || !mlx)
		return ;
	mlx_delete_image(mlx, textures->ground);
	mlx_delete_image(mlx, textures->wall);
	mlx_delete_image(mlx, textures->player);
	mlx_delete_image(mlx, textures->collectible);
	mlx_delete_image(mlx, textures->exit);
	free(textures);
	textures = NULL;
};
void	free_app(t_app app)
{
	free_map(app.game.map);
	free_textures(app.mlx, app.textures);
}