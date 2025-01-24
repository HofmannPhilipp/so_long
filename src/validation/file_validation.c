/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:16:34 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/24 15:46:10 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *path, char *extension)
{
	int	i;
	int	j;
	char *filename;

	filename = ft_strrchr(path, '/');
	if (!filename)
		filename = path;
	else
		filename++;
	i = ft_strlen(filename) - 1;
	j = ft_strlen(extension) - 1;
	if (i == j)
		return (EXIT_FAILURE);
	while (j >= 0)
	{
		if (filename[i] != extension[j])
			return (EXIT_FAILURE);
		i--;
		j--;
	}
	return (EXIT_SUCCESS);
}
