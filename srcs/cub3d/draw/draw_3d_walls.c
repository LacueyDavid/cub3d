/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:16:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 14:58:59 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "libft_and_utils.h"
#include <math.h>
#include <mlx.h>

static void	protect_line_height(int *line_h, int max)
{
	if (*line_h < 0)
		*line_h = 0;
	if (*line_h > max)
		*line_h = max;
}

static float	fix_fisheye(t_cub3D_data *data, t_ray *ray)
{
	float	correct_angle;
	float	distance;

	correct_angle = ray->angle - data->player.angle;
	if (correct_angle < 0)
		correct_angle += 2 * M_PI;
	if (correct_angle > 2 * M_PI)
		correct_angle -= 2 * M_PI;
	distance = ray->distance * cos(correct_angle);
	return (distance);
}

// int	get_pixel_color(t_img_data img, int x, int y)
// {
// 	int	color;
//
// 	color = *(int *)(img.address + (y * img.line_length + x
// 				* (img.bits_per_pixel / 8)));
// 	return (color);
// }
//

void	set_ceiling(t_cub3D_data *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < HEIGHT / 2)
	{
		my_mlx_pixel_put(&data->img_data, ray->numbers
			+ (WIDTH / 2) - (ray->max / 2),
			i, rgb_to_int(data->map_data.ceiling_color));
		i++;
	}
}

void	set_floor(t_cub3D_data *data, t_ray *ray)
{
	int	i;

	i = HEIGHT / 2;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(&data->img_data, ray->numbers
			+ (WIDTH / 2) - (ray->max / 2),
			i, rgb_to_int(data->map_data.floor_color));
		i++;
	}
}

void	draw_3d_walls(t_cub3D_data *data, t_ray *ray)
{
	int				line_height;
	t_line			line;
	int				line_offset;

	ray->distance = fix_fisheye(data, ray);
	line_height = (ray->max * (data->map_data.gap)) / ray->distance;
	ray->line_height = line_height;
	protect_line_height(&line_height, ray->max);
	line_offset = ray->max / 2 - line_height / 2;
	line.p1.x = ray->numbers + (WIDTH / 2) - (ray->max / 2);
	line.p1.y = line_offset;
	line.p2.x = ray->numbers + (WIDTH / 2) - (ray->max / 2);
	line.p2.y = line_height + line_offset;
	set_floor(data, ray);
	set_ceiling(data, ray);
	textured_rasterization(line, &data->img_data, ray, data);
}
