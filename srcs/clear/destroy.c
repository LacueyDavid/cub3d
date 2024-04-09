/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:35:24 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/08 20:36:12 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

void	destroy_map(t_map_enum **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_img(t_map_data *data)
{
	free(data->img[NORTH].path);
	free(data->img[SOUTH].path);
	free(data->img[WEST].path);
	free(data->img[EAST].path);
	free(data->img[NORTH].img);
	free(data->img[SOUTH].img);
	free(data->img[WEST].img);
	free(data->img[EAST].img);
	free(data->img[NORTH].mlx);
	free(data->img[SOUTH].mlx);
	free(data->img[WEST].mlx);
	free(data->img[EAST].mlx);
}
