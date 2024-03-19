/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "mlx.h"
#include <math.h>

int	which_is_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

typedef struct ray
{
	float angle;
	float x;
	float y;
	float x_offset;
	float y_offset;
	float numbers;
	float depth_of_field;
} t_ray;

float aTan;

#include <stdio.h>

void	looking_up(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;
	if (ray->angle > M_PI)
	{
		ray->y =  (((int)data->player.position.y / gap) * gap) -4;
		ray->x = (data->player.position.y - ray->y) * aTan + data->player.position.x;
		ray->y_offset = -gap;
		ray->x_offset = -ray->y_offset * aTan;
	}
}

void	looking_down(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;
	if (ray->angle < M_PI)
	{
		ray->y =  (((int)data->player.position.y / gap) * gap) + gap -4;
		ray->x = (data->player.position.y - ray->y) * aTan + data->player.position.x;
		ray->y_offset = gap;
		ray->x_offset = -ray->y_offset * aTan;
	}
}

void	looking_sides(t_cub3D_data *data, t_ray *ray)
{
	int		bigger;

	bigger = which_is_bigger(data->map_data.width, data->map_data.height);
	if (ray->angle == 0)
	{
		ray->x = data->player.position.x;
		ray->y = data->player.position.y;
		ray->depth_of_field = bigger;
	}
}

int	is_wall(t_cub3D_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_data.width || y < 0 || y >= data->map_data.height)
		return (1);
	return (data->map_data.map[y][x] == WALL);
}

void	fire_rays_until_wall(t_cub3D_data *data, t_ray *ray)
{
	int		bigger;
	int		map_x;
	int		map_y;
	int		gap;
	t_line	line;

	gap = data->map_data.gap;
	bigger = which_is_bigger(data->map_data.width, data->map_data.height);
	while (ray->depth_of_field < bigger)
	{
		map_x = (int)ray->x / gap;
		map_y = (int)ray->y / gap;
		printf("x = %d, y = %d\n", map_x, map_y);
		if (is_wall(data, map_x, map_y))
		{
			ray->depth_of_field = bigger;
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field += 1; // go to next line
		}
	}
	line.p1.x = data->player.position.x;
	line.p1.y = data->player.position.y;
	line.p2.x = ray->x;
	line.p2.y = ray->y;
	rasterization(line, &data->img_data, rgb_to_int(data->player.color));
}

void	draw_rays_3d(t_cub3D_data *data)
{
	t_ray	ray;

	ray.angle = data->player.angle;
	aTan = -1 / tan(ray.angle);
	ray.numbers = 0;
	while (ray.numbers < 1)
	{
		looking_up(data, &ray);
		looking_down(data, &ray);
		looking_sides(data, &ray);
		fire_rays_until_wall(data, &ray);
		ray.numbers += 1;
	}
}

// la fonction reset_image va surement disparaitre plus tard
int	cub3d(t_cub3D_data *data)
{
	reset_image(&data->img_data);
	draw_minimap(data);
	draw_player(data->player, data->img_data);
	draw_rays_3d(data);
	mlx_put_image_to_window(data->window.mlx,
							data->window.address, data->img_data.img, 0, 0);
	return (1);
}
