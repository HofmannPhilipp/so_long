/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:35 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/10 13:28:59 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_grid(char **grid)
{
	if (check_dimensions(grid) == EXIT_FAILURE)
		handle_error("Map dimensions wrong");
	if (check_walls(grid) == EXIT_FAILURE)
		handle_error("Map walls wrong");
	if (check_for_valid_chars(grid) == EXIT_FAILURE)
		handle_error("Map chars wrong");
	if (check_valid_amount_componens(grid) == EXIT_FAILURE)
		handle_error("Map has not valid amount of components");
}

int	check_valid_amount_componens(char **grid)
{
	int	e_count;
	int	p_count;
	int	c_count;

	e_count = 0;
	p_count = 0;
	c_count = 0;
	while (*grid != NULL)
	{
		while (**grid != '\0')
		{
			if (**grid == 'E')
				e_count++;
			if (**grid == 'P')
				p_count++;
			if (**grid == 'C')
				c_count++;
			(*grid)++;
		}
		grid++;
	}
	if (e_count > 1 || p_count > 1 || c_count < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_for_valid_chars(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] != '0' && grid[i][j] != '1' && grid[i][j] != 'C' && grid[i][j] != 'E' && grid[i][j] != 'P')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_walls(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if ((i == 0 || grid[i + 1] == NULL) && grid[i][j] != '1')
				return (EXIT_FAILURE);
			if ((j == 0 || grid[i][j + 1] == '\0') && grid[i][j] != '1')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_dimensions(char **grid)
{
	size_t	width;
	size_t	height;
	
	width = ft_strlen(*grid);
	height = 0;
	while (*grid != NULL)
	{
		if (width != ft_strlen(*grid))
			return (EXIT_FAILURE);
		height++;
		grid++;
	}
	if (height == width)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_file_extension(char *path, char *extension)
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
			handle_error("Wrong file extension");
		i--;
		j--;
	}
}