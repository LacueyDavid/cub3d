/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:35:24 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 11:44:24 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
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
	mlx_destroy_image(data->img[NORTH].mlx, data->img[NORTH].img);
	mlx_destroy_image(data->img[SOUTH].mlx, data->img[SOUTH].img);
	mlx_destroy_image(data->img[WEST].mlx, data->img[WEST].img);
	mlx_destroy_image(data->img[EAST].mlx, data->img[EAST].img);
	mlx_destroy_display(data->img[NORTH].mlx);
	mlx_destroy_display(data->img[SOUTH].mlx);
	mlx_destroy_display(data->img[WEST].mlx);
	mlx_destroy_display(data->img[EAST].mlx);
	free(data->img[NORTH].mlx);
	free(data->img[SOUTH].mlx);
	free(data->img[WEST].mlx);
	free(data->img[EAST].mlx);
}
