/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/14 11:19:36 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 )
	{
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./so_long <map_file.ber>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	data.game = init_game_state(argv[1]);
	// validate_grid(map.grid);
	data.mlx = mlx_init();
	if (!data.mlx)
		handle_error("failed to init");

	data.window = mlx_new_window(data.mlx, data.game.width * 50, data.game.height * 50, "Duck saves the world");
	if (!data.window)
		handle_error("failed to open window");
	mlx_expose_hook(data.window, render_map, &data);
	mlx_key_hook(data.window, move, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
