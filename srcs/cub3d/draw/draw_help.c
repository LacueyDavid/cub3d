/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:30:12 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

int	is_wall(t_cub3d_data *data, int x, int y)
{
	if (x < 0
		|| x >= data->map_data.width
		|| y < 0
		|| y >= data->map_data.height)
		return (1);
	if (data->map_data.map[y][x] == WALL)
		return (1);
	return (0);
}

float	calculate_ray_distance(t_ray *ray, t_cub3d_data *data)
{
	float	cosinus;
	float	sinus;
	float	abscissa_ray_end_point;
	float	ordinate_ray_end_point;

	cosinus = cos(ray->angle);
	sinus = sin(ray->angle);
	abscissa_ray_end_point = ray->x - data->player.position.x;
	ordinate_ray_end_point = ray->y - data->player.position.y;
	return (cosinus * abscissa_ray_end_point - sinus * ordinate_ray_end_point);
}
