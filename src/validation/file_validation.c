/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:16:34 by phhofman          #+#    #+#             */
/*   Updated: 2025/01/21 16:42:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
