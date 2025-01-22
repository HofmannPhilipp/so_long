/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:07:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/22 16:32:57 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game_state(char *file)
{
	t_game	game;

	game.map = create_map(file);
	set_map_size(&game);
	set_player(&game);
	game.moves = 0;
	return (game);
}

int	is_game_finished(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] == 'C' || game.map[y][x] == 'E')
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	is_exit_unlocked(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] == 'C')
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
