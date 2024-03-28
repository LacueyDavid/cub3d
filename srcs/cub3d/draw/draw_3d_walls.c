/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:16:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 09:02:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "libft_and_utils.h"
#include <math.h>

static void	protect_line_height(int *lineH, int max)
{
	if (*lineH < 0)
		*lineH = 0;
	if (*lineH > max)
		*lineH = max;
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

void	draw_3d_walls(t_cub3D_data *data, t_ray *ray)
{
	int				line_height;
	t_line			line;
	t_color_rgb		color;
	int				line_offset;

	ray->distance = fix_fisheye(data, ray);
	line_height = (ray->max * (data->map_data.gap)) / ray->distance;
	protect_line_height(&line_height, ray->max);
	line_offset = ray->max / 2 - line_height / 2;
	set_color(&color, 255, 255, 0);
	line.p1.x = ray->numbers + (WIDTH / 2) - (ray->max / 2);
	line.p1.y = line_offset;
	line.p2.x = ray->numbers + (WIDTH / 2) - (ray->max / 2);
	line.p2.y = line_height + line_offset;
	rasterization(line, &data->img_data, rgb_to_int(color));
}
