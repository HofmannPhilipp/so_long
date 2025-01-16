/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:35 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/16 13:39:17 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_map(char **map)
{
	if (check_dimensions(map) == EXIT_FAILURE)
		handle_error("Map dimensions wrong");
	if (check_walls(map) == EXIT_FAILURE)
		handle_error("Map walls wrong");
	if (check_for_valid_chars(map) == EXIT_FAILURE)
		handle_error("Map chars wrong");
	if (check_valid_amount_componens(map) == EXIT_FAILURE)
		handle_error("Map has not valid amount of components");
}

int	check_valid_amount_componens(char **map)
{
	int	e_count;
	int	p_count;
	int	c_count;
	int	i;
	int	j;

	e_count = 0;
	p_count = 0;
	c_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				e_count++;
			if (map[i][j] == 'P')
				p_count++;
			if (map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (e_count > 1 || p_count > 1 || c_count < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_for_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || map[i + 1] == NULL) && map[i][j] != '1')
				return (EXIT_FAILURE);
			if ((j == 0 || map[i][j + 1] == '\0') && map[i][j] != '1')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_dimensions(char **map)
{
	size_t	width;
	size_t	height;
	
	width = ft_strlen(*map);
	height = 0;
	while (map[height] != NULL)
	{
		if (width != ft_strlen(map[height]))
			return (EXIT_FAILURE);
		height++;
	}
	if (height == width)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_file_extension(char *path, char *extension)
{
	int	i;
	int	j;

	i = 0;
	while (path[i] != '\0')
		i++;
	j = 0;
	while (extension[j] != '\0')
		j++;
	while (j >= 0)
	{
		if (path[i] != extension[j])
			return (EXIT_FAILURE);
		i--;
		j--;
	}
	return (EXIT_SUCCESS);
}
