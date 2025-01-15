/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/15 15:40:29 by phhofman         ###   ########.fr       */
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
	int	i;

	i = 0;
	while(map[i] != NULL)
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

// t_img	init_img(void *mlx, char *path)
// {
// 	t_img	img;

// 	img.path = path;
// 	img.img = mlx_png_file_to_image(mlx, path, &img.width, &img.height);
// 	if (img.img == NULL)
// 		handle_error("could not load image");
// 	return (img);
// }

void	free_map(char **map)
{
	int	i;

	i = 0;
	while(map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
