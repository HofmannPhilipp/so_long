/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:35 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/22 10:46:41 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(t_game game)
{
	if (check_dimensions(game.map) == EXIT_FAILURE)
	{
		free_map(game.map);
		handle_error("Map dimensions wrong");
	}
	if (check_walls(game.map) == EXIT_FAILURE)
	{
		free_map(game.map);
		handle_error("Map walls wrong");
	}
	if (check_for_valid_chars(game.map) == EXIT_FAILURE)
	{
		free_map(game.map);
		handle_error("Map chars wrong");
	}
	if (check_valid_amount_componens(game.map) == EXIT_FAILURE)
	{
		free_map(game.map);
		handle_error("Map has not valid amount of components");
	}
	if (check_valid_pathway(game) == EXIT_FAILURE)
	{
		free_map(game.map);
		handle_error("Map has not valid pathway");
	}
}
