/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:58:47 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/07 14:45:31 by phhofman         ###   ########.fr       */
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
	char		*line;

	map = (char *)malloc(sizeof(char *));
	if (map == NULL)
		handle_error(NULL);
	// todo: checken ob ich einmal die lange der mit gnl berechne um dann zu wissen wie viele pointer ich im 2d arry map brauche
	while ((line = get_next_line(fd)) != NULL)
	{

	}
}
char	*read_line(int fd)
{
	char		*line;
	while ((line = get_next_line(fd)) != NULL)
	{

	}
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


