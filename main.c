/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/24 15:43:12 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_app	app;

	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("Invalid number of arguments.\n");
		return (EXIT_FAILURE);
	}
	app = init_app(argv[1]);
	render_map(&app);
	mlx_close_hook(app.mlx, close_game, &app);
	mlx_key_hook(app.mlx, handle_keypress, &app);
	mlx_loop(app.mlx);
	free_app(app);
	mlx_terminate(app.mlx);
	return (EXIT_SUCCESS);
}
