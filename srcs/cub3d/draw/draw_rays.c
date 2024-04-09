/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:07:13 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "libft_and_utils.h"
#include "draw.h"
#include <stdio.h>

void	prepare_next_ray(t_ray *ray)
{
	ray->numbers += 1;
	ray->angle -= (ray->angle_precision);
	if (ray->angle < 0)
		ray->angle += 2 * M_PI;
	if (ray->angle > 2 * M_PI)
		ray->angle -= 2 * M_PI;
}

void	set_ray(t_ray *ray, t_cub3d_data *data)
{
	ray->x = 0;
	ray->y = 0;
	ray->x_offset = 0;
	ray->y_offset = 0;
	ray->vx = 0;
	ray->vy = 0;
	ray->distance = 0;
	ray->distance_v = 100000;
	ray->distance_h = 100000;
	ray->smallest_distance = 0;
	ray->depth_of_field = 0;
	ray->numbers = 0;
	ray->max = data->map_data.screen_smallest_side;
	ray->angle_precision = (M_PI / 180) * FOV / ray->max;
	ray->angle = data->player.angle + (M_PI / 180) * (FOV / 2);
	if (ray->angle < 0)
		ray->angle += 2 * M_PI;
	if (ray->angle > 2 * M_PI)
		ray->angle -= 2 * M_PI;
}

void	draw_rays(t_cub3d_data *data)
{
	t_ray	ray;

	set_ray(&ray, data);
	while (ray.numbers < ray.max)
	{
		set_current_ray_distance(&ray, data);
		if (data->key.tab)
			draw_minimap_2d_ray(data, &ray);
		draw_3d_walls(data, &ray);
		prepare_next_ray(&ray);
	}
}
