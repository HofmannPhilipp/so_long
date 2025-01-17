/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/17 16:22:21 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_app	app;

	if (argc != 2 )
	{
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./so_long <map_file.ber>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	
	app = init_app(argv[1]);
	render_map(&app);
	mlx_close_hook(app.mlx, close_game, &app);
	mlx_key_hook(app.mlx, handle_keypress, &app);
	// mlx_resize_hook(app.mlx, resize_window, &app);
	mlx_loop(app.mlx);
	mlx_terminate(app.mlx);
	free_app(app);
	return (EXIT_SUCCESS);
}
