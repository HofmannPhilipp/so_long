/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:58:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/08 15:14:28 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_map(char *path)
{
	int		fd;
	char	**map;
	if (check_file_extension(path, ".ber") == EXIT_FAILURE)
	{
		ft_putstr_fd("Error: Invalid file extension. The map description file must have a .ber extension.\n",STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(NULL);
	char	*str;

	str = read_all_lines(fd);
	map = ft_split(str, '\n');
	if (map == NULL)
		handle_error("Failed ft_split in func crate_map");
	return (map);
}

char	*read_all_lines(int fd)
{
	char	*curr_line;
	char	*combined_lines;
	char	*temp;

	combined_lines = ft_strdup("");
	if (combined_lines == NULL)
		handle_error("Malloc failed in func: read_line");
	while ((curr_line = get_next_line(fd)) != NULL)
	{
		temp = combined_lines;
		combined_lines = ft_strjoin(combined_lines, curr_line);
		free(temp);
		free(curr_line);
		if (combined_lines == NULL)
			handle_error("Malloc failed in func: read_line");
	}
	return (combined_lines);
}

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

	e_count = 0;
	p_count = 0;
	c_count = 0;
	while (*map != NULL)
	{
		while (**map != '\0')
		{
			if (**map == 'E')
				e_count++;
			if (**map == 'P')
				p_count++;
			if (**map == 'C')
				c_count++;
			(*map)++;
		}
		map++;
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
	while (*map != NULL)
	{
		if (width != ft_strlen(*map))
			return (EXIT_FAILURE);
		height++;
		map++;
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


