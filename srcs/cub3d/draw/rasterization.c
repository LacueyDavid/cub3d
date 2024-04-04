/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:42:36 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/04 12:08:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "image_data.h"
#include "draw.h"
#include <stdlib.h>

static t_point	define_direction(t_line line)
{
	t_point	direction;

	if (line.p1.x < line.p2.x)
		direction.x = 1;
	else
		direction.x = -1;
	if (line.p1.y < line.p2.y)
		direction.y = 1;
	else
		direction.y = -1;
	return (direction);
}

void	rasterization(t_line line, t_img_data *img, int color)
{
	int		error;
	int		err2;
	t_point	diff;
	t_point	direction;

	direction = define_direction(line);
	diff.x = abs((int)line.p2.x - (int)line.p1.x);
	diff.y = -abs((int)line.p2.y - (int)line.p1.y);
	error = diff.x + diff.y;
	while (line.p1.x != line.p2.x || line.p1.y != line.p2.y)
	{
		my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
		err2 = 2 * error;
		if (err2 >= diff.y)
		{
			error += diff.y;
			line.p1.x += direction.x;
		}
		if (err2 <= diff.x)
		{
			error += diff.x;
			line.p1.y += direction.y;
		}
	}
	my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
}

static int	get_pixel_color(t_imgs img, int x, int y)
{
	int	color;

	color = *(int *)(img.data.address + (y * img.data.line_length + x
				* (img.data.bits_per_pixel / 8)));
	return (color);
}

void	textured_rasterization(t_line line, t_img_data *img, t_ray *ray, t_imgs texture)
{
	int		error;
	int		err2;
	t_point	diff;
	t_point	direction;
	int		color;
	(void)ray;


	direction = define_direction(line);
	diff.x = abs((int)line.p2.x - (int)line.p1.x);
	diff.y = -abs((int)line.p2.y - (int)line.p1.y);
	error = diff.x + diff.y;
	while (line.p1.x != line.p2.x || line.p1.y != line.p2.y)
	{
		color = get_pixel_color(texture, line.p1.x % texture.width, line.p1.y % texture.height);
		my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
		err2 = 2 * error;
		if (err2 >= diff.y)
		{
			error += diff.y;
			line.p1.x += direction.x;
		}
		if (err2 <= diff.x)
		{
			error += diff.x;
			line.p1.y += direction.y;
		}
	}
	color = get_pixel_color(texture, line.p1.x, line.p1.y);
	my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
}
