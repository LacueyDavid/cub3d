/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:36:40 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 02:07:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include <math.h>

static void	fire_ray(t_cub3D_data *data, t_ray *ray, float *distance)
{
	int		map_x;
	int		map_y;
	int		gap;

	gap = data->map_data.gap;
	while (ray->depth_of_field < data->map_data.biggest_side)
	{
		map_x = (int)((ray->x) / gap);
		map_y = (int)((ray->y) / gap);
		if (is_wall(data, map_x, map_y))
		{
			ray->depth_of_field = data->map_data.biggest_side;
			*distance = calculate_ray_distance(ray, data);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field += 1;
		}
	}
}

static void	set_ray_horizontal_distance(t_cub3D_data *data, t_ray *ray,
										int biggest_side)
{
	ray->invert_tan = 1.0 / tan(ray->angle);
	ray->depth_of_field = 0;
	if (sin(ray->angle) > 0.001)
		looking_up(data, ray);
	else if (sin(ray->angle) < -0.001)
		looking_down(data, ray);
	else
		looking_straight_sides(data, ray, &biggest_side);
	fire_ray(data, ray, &ray->distance_h);
}

static void	set_ray_vertical_distance(t_cub3D_data *data, t_ray *ray,
										int biggest_side)
{
	ray->tan = tan(ray->angle);
	ray->depth_of_field = 0;
	if (cos(ray->angle) < -0.001)
		looking_right(data, ray);
	else if (cos(ray->angle) > 0.001)
		looking_left(data, ray);
	else
		looking_straight_sides(data, ray, &biggest_side);
	fire_ray(data, ray, &ray->distance_v);
	ray->vx = ray->x;
	ray->vy = ray->y;
}

static void	choose_smallest_distance(t_ray *ray)
{
	if (ray->distance_v < ray->distance_h)
	{
		ray->x = ray->vx;
		ray->y = ray->vy;
		ray->distance = ray->distance_v;
	}
	else
		ray->distance = ray->distance_h;
}

void	set_current_ray_distance(t_ray *ray, t_cub3D_data *data)
{
	set_ray_vertical_distance(data, ray, data->map_data.biggest_side);
	set_ray_horizontal_distance(data, ray, data->map_data.biggest_side);
	choose_smallest_distance(ray);
}
