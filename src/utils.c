/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/24 17:17:27 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(char *error_msg)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	*read_all_lines(int fd)
{
	char	*curr_line;
	char	*combined_lines;
	char	*temp;

	combined_lines = ft_strdup("");
	if (!combined_lines)
	{
		close(fd);
		handle_error("Malloc failed in func: read_all_lines");
	}
	curr_line = get_next_line(fd);
	while (curr_line != NULL)
	{
		temp = combined_lines;
		combined_lines = ft_strjoin(combined_lines, curr_line);
		free(temp);
		free(curr_line);
		if (!combined_lines)
		{
			close(fd);
			handle_error("Malloc failed in func: read_all_lines");
		}
		curr_line = get_next_line(fd);
	}
	return (combined_lines);
}

int	count_component(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**copy_map(t_game game)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (game.height + 1));
	if (!new_map)
		handle_error("Malloc failed in func: copy_map");
	while (game.map[i] != NULL)
	{
		new_map[i] = ft_strdup(game.map[i]);
		if (!new_map[i])
			handle_error("Malloc failed in func: copy_map");
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
