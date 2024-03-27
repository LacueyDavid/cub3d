/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/27 14:03:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "mlx.h"
#include <math.h>
#include "libft_and_utils.h"

#include <stdio.h>

int	which_is_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	which_is_lower(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

void	looking_left(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;

	ray->x = (((int)data->player.position.x / gap) * gap) + gap;
	ray->y = (data->player.position.x - ray->x) * ray->tan + data->player.position.y;
	ray->x_offset = gap;
	ray->y_offset = -ray->x_offset * ray->tan;
}

void	looking_right(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;

	ray->x = (((int)data->player.position.x / gap) * gap) - 0.0001;
	ray->y = (data->player.position.x - ray->x) * ray->tan + data->player.position.y;
	ray->x_offset = -gap;
	ray->y_offset = -ray->x_offset * ray->tan;
}

void	looking_up(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;

	ray->y = (((int)data->player.position.y / gap) * gap) - 0.0001;
	ray->x = (data->player.position.y - ray->y) * ray->invert_tan + data->player.position.x;
	ray->y_offset = -gap;
	ray->x_offset = -ray->y_offset * ray->invert_tan;
}

void	looking_down(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;

	ray->y = (((int)data->player.position.y / gap) * gap) + gap;
	ray->x = (data->player.position.y - ray->y) * ray->invert_tan + data->player.position.x;
	ray->y_offset = gap;
	ray->x_offset = -ray->y_offset * ray->invert_tan;
}

void	looking_straight_sides(t_cub3D_data *data, t_ray *ray, int *bigger)
{
	ray->x = data->player.position.x;
	ray->y = data->player.position.y;
	ray->depth_of_field = *bigger;
}

int	is_wall(t_cub3D_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_data.width || y < 0 || y >= data->map_data.height)
		return (1);
	if (data->map_data.map[y][x] == WALL)
		return (1);
	return (0);
}

void	draw_minimap_2d_ray(t_cub3D_data *data, t_ray *ray)
{
	t_line	line;
	t_color_rgb	color;

	color.r = 0;
	color.g = 255;
	color.b = 255;

	line.p1.x = (int)data->player.position.x;
	line.p1.y = (int)data->player.position.y;
	line.p2.x = (int)ray->x;
	line.p2.y = (int)ray->y;
	rasterization(line, &data->img_data, rgb_to_int(color));
}

void	fire_horizontal_ray(t_cub3D_data *data, t_ray *ray, int *bigger, float *disH)
{
	int		map_x;
	int		map_y;
	int		gap;

	gap = data->map_data.gap;
	while (ray->depth_of_field < *bigger)
	{
		map_x = (int)(ray->x / gap);
		map_y = (int)(ray->y / gap);
		if (is_wall(data, map_x, map_y))
		{
			ray->depth_of_field = *bigger;
			*disH = cos(ray->angle) * (ray->x - data->player.position.x) - sin(ray->angle) * (ray->y - data->player.position.y);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field += 1; // go to next line
		}
	}
}

void	fire_vertical_ray(t_cub3D_data *data, t_ray *ray, int *bigger, float *disV)
{
	int		map_x;
	int		map_y;
	int		gap;

	gap = data->map_data.gap;
	while (ray->depth_of_field < *bigger)
	{
		map_x = (int)((ray->x) / gap);
		map_y = (int)((ray->y) / gap);
		if (is_wall(data, map_x, map_y))
		{
			ray->depth_of_field = *bigger;
			*disV = cos(ray->angle) * (ray->x - data->player.position.x) - sin(ray->angle) * (ray->y - data->player.position.y);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field += 1; // go to next line
		}
	}
	ray->vx = ray->x;
	ray->vy = ray->y;
}

void	draw_3d_walls(t_cub3D_data *data, t_ray *ray, float disH)
{
	int				lineH;
	t_line			line;
	t_color_rgb		color;
	int				lineOff;
	float			cosinus_angle;
	int				bigger;

	bigger = which_is_lower(WIDTH, HEIGHT);
	cosinus_angle = data->player.angle - ray->angle;
	if (cosinus_angle < 0)
		cosinus_angle += 2 * M_PI;
	if (cosinus_angle > 2 * M_PI)
		cosinus_angle -= 2 * M_PI;
	disH = disH * cos(cosinus_angle);
	lineH = (bigger * (data->map_data.gap)) / disH;
	if (lineH > bigger)
		lineH = bigger;
	lineOff = bigger / 2 - (lineH>>1);
	color.r = 255;
	color.g = 255;
	color.b = 0;
	int ray_v_nb = 0;
	line.p1.x = ray->numbers + (WIDTH / 2) - (FOV    / 2) + ray_v_nb;
	line.p1.y = lineOff;
	line.p2.x = ray->numbers + (WIDTH / 2) - (FOV    / 2) + ray_v_nb;
	line.p2.y = lineH + lineOff;
	rasterization(line, &data->img_data, rgb_to_int(color));
}

void	draw_rays_2d(t_cub3D_data *data)
{
	t_ray	ray;
	int		bigger;
	float	disV;
	float	disH;

	disV = 100000; //enlever le nombre magique
	disH = 100000; //enlever le nombre magique
	bigger = which_is_bigger(data->map_data.width, data->map_data.height);
	ray.angle = data->player.angle;
	ray.numbers = 0;
	ray.angle = data->player.angle + (M_PI / 180 / 20) * (FOV / 2);
	if (ray.angle < 0)
		ray.angle += 2 * M_PI;
	if (ray.angle > 2 * M_PI)
		ray.angle -= 2 * M_PI;
	while (ray.numbers < FOV)
	{
		// vertical rays
		ray.tan = tan(ray.angle);
		ray.depth_of_field = 0;
		if (cos(ray.angle) < -0.001)
			looking_right(data, &ray);
		else if (cos(ray.angle) > 0.001)
			looking_left(data, &ray);
		else
			looking_straight_sides(data, &ray, &bigger);
		fire_vertical_ray(data, &ray, &bigger, &disV);
		// horizontal rays
		ray.invert_tan = 1.0 / tan(ray.angle);
		ray.depth_of_field = 0;
		if (sin(ray.angle) > 0.001)
			looking_up(data, &ray);
		else if (sin(ray.angle) < -0.001)
			looking_down(data, &ray);
		else
			looking_straight_sides(data, &ray, &bigger);
		fire_horizontal_ray(data, &ray, &bigger, &disH);
		if (disV < disH)
		{
			ray.x = ray.vx;
			ray.y = ray.vy;
			ray.distance = disV;
			disH = disV;
		}
		ray.distance = disH;
		draw_minimap_2d_ray(data, &ray);
		draw_3d_walls(data, &ray, disH);
		ray.numbers += 1;
		ray.angle -= (M_PI / 180 / 20);
		if (ray.angle < 0)
			ray.angle += 2 * M_PI;
		if (ray.angle > 2 * M_PI)
			ray.angle -= 2 * M_PI;
	}
}

// la fonction reset_image va surement disparaitre plus tard
int	cub3d(t_cub3D_data *data)
{
	reset_image(&data->img_data);
	draw_rays_2d(data);
	draw_minimap(data);
	draw_player(data->player, data->img_data);
	mlx_put_image_to_window(data->window.mlx,
							data->window.address, data->img_data.img, 0, 0);
	return (1);
}
