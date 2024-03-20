/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/20 16:02:26 by dlacuey          ###   ########.fr       */
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

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

void	looking_left(t_cub3D_data *data, t_ray *ray)
{
	int gap = data->map_data.gap;
	ray->x =  (((int)data->player.position.x / gap) * gap - 4 - 0.0001);
	ray->y = (data->player.position.x - ray->x) * ray->negative_tan + data->player.position.y;
	ray->x_offset = -gap;
	ray->y_offset = -ray->x_offset * ray->negative_tan;
}

void	looking_right(t_cub3D_data *data, t_ray *ray)
{
	printf("player y = %f\n", data->player.position.y);
	printf("negative tan = %f\n", ray->negative_tan);
	printf("player x = %f\n", data->player.position.x);
	printf("ray x = %f\n", ray->x);
	printf("position x = %f\n", data->player.position.x);
	int gap = data->map_data.gap;
	ray->x = (((int)data->player.position.x / gap) * gap) + gap - 4;
	ray->y = (data->player.position.x - ray->x) * ray->negative_tan + data->player.position.y;
	ray->x_offset = gap;
	ray->y_offset = -ray->x_offset * ray->negative_tan;
}
//
// void	looking_up(t_cub3D_data *data, t_ray *ray)
// {
// 	int gap = data->map_data.gap;
// 	ray->y =  (((int)data->player.position.y / gap) * gap - 4 - 0.0001);
// 	ray->x = (data->player.position.y - ray->y) * ray->opposite_invert_tan + data->player.position.x;
// 	ray->y_offset = -gap;
// 	ray->x_offset = -ray->y_offset * ray->opposite_invert_tan;
// }
//
// void	looking_down(t_cub3D_data *data, t_ray *ray)
// {
// 	int gap = data->map_data.gap;
// 	ray->y = (((int)data->player.position.y / gap) * gap) + gap - 4;
// 	ray->x = (data->player.position.y - ray->y) * ray->opposite_invert_tan + data->player.position.x;
// 	ray->y_offset = gap;
// 	ray->x_offset = -ray->y_offset * ray->opposite_invert_tan;
// }

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

void	draw_ray(t_cub3D_data *data, t_ray *ray)
{
	t_line	line;

	line.p1.x = (int)data->player.position.x;
	line.p1.y = (int)data->player.position.y;
	line.p2.x = ray->x;
	line.p2.y = ray->y;
	printf("ray y = %f\n", ray->y);
	rasterization(line, &data->img_data, rgb_to_int(data->player.color));
	printf("ok salope\n");
}

void	fire_rays_until_wall(t_cub3D_data *data, t_ray *ray, int *bigger)
{
	int		map_x;
	int		map_y;
	int		gap;

	gap = data->map_data.gap;
	while (ray->depth_of_field < *bigger)
	{
		map_x = (int)((ray->x - WIDTH / 70) / gap);
		map_y = (int)((ray->y - WIDTH / 70) / gap);
		if (is_wall(data, map_x, map_y))
		{
			ray->depth_of_field = *bigger;
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field += 1; // go to next line
		}
	}
	draw_ray(data, ray);
}

void	draw_rays_3d(t_cub3D_data *data)
{
	t_ray	ray;
	int		bigger;

	bigger = which_is_bigger(data->map_data.width, data->map_data.height);
	ray.angle = data->player.angle;
	ray.numbers = 0;
	while (ray.numbers < 1)
	{
		// ray.negative_invert_tan = -1 / tan(ray.angle);
		// ray.depth_of_field = 0;
		// if (ray.angle > M_PI)
		// 	looking_up(data, &ray);
		// else if (ray.angle < M_PI)
		// 	looking_down(data, &ray);
		// else
		// 	looking_straight_sides(data, &ray, &bigger);
		printf("ray angle = %f\n", ray.angle);
		ray.negative_tan = -tan(ray.angle);
		ray.depth_of_field = 0;
		if (ray.angle > M_PI / 2 && ray.angle < 3 * M_PI / 2)
			looking_left(data, &ray);
		else if (ray.angle < M_PI / 2 || ray.angle > 3 * M_PI / 2)
			looking_right(data, &ray);
		else
			looking_straight_sides(data, &ray, &bigger);
		fire_rays_until_wall(data, &ray, &bigger);
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
