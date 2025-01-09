/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/09 11:13:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	print_map(char **map)
{
	while(*map != NULL)
	{
		ft_printf("%s\n", *map);
		map++;
	}
}

