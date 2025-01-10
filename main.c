/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:05 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/10 15:05:40 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2 )
	{
		ft_putstr_fd("Error: Invalid number of arguments. Usage: ./so_long <map_file.ber>", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	map = create_map(argv[1]);
	// validate_grid(map.grid);
	render_map(map);
	return (EXIT_SUCCESS);
}
