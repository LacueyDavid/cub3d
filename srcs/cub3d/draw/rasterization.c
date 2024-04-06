/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:42:36 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 13:24:23 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "image_data.h"
#include "draw.h"
#include "cub3d_useful_values.h"
#include <math.h>
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

int	color_blue(void)
{
	return (0x0000FF);
}

int	color_green(void)
{
	return (0x00FF00);
}

void	textured_rasterization(t_line line, t_img_data *img, t_ray *ray, t_cub3D_data *data)
{
	int		error;
	int		err2;
	t_point	diff;
	t_point	direction;
	int		color;
	//add
	t_imgs	texture = data->map_data.img[NORTH];
	int		gap = data->map_data.gap * texture.width;
	int		start_y = line.p1.y;
	int position_y = 0;
	int position_x = 0;
	int ecart;
	(void)ray;


	color = 0;
	ecart = ray->lineH / 2 - HEIGHT / 2;
	if (ecart < 0)
		ecart = 0;


	direction = define_direction(line);
	diff.x = abs((int)line.p2.x - (int)line.p1.x);
	diff.y = -abs((int)line.p2.y - (int)line.p1.y);
	error = diff.x + diff.y;
	while (line.p1.x != line.p2.x || line.p1.y != line.p2.y)
	{
		if (ray->smallest_distance == ray->distance_h && ray->angle > M_PI)
		{
			texture = data->map_data.img[NORTH];
			color = get_pixel_color(texture, position_x, position_y);
			position_y = (ecart + (line.p1.y - start_y)) * texture.height / ray->lineH;
			if (position_y < 0)
				position_y = 0;
			if (position_y >= texture.height)
				position_y = texture.height - 1;
			position_x = ((int)(ray->x * texture.width) % gap) * texture.width / gap;
			if (position_x < 0)
				position_x = 0;
			if (position_x >= texture.width)
				position_x = texture.width - 1;
		}
		else if (ray->smallest_distance == ray->distance_v && (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2))
		{
			texture = data->map_data.img[WEST];
			color = get_pixel_color(texture, position_x, position_y);
			position_y = (ecart + (line.p1.y - start_y)) * texture.height / ray->lineH;
			if (position_y < 0)
				position_y = 0;
			if (position_y >= texture.height)
				position_y = texture.height - 1;
			position_x = ((int)(ray->y * texture.width) % gap) * texture.width / gap;
			if (position_x < 0)
				position_x = 0;
			if (position_x >= texture.width)
				position_x = texture.width - 1;
		}
		else if (ray->smallest_distance == ray->distance_v && (ray->angle > M_PI / 2 || ray->angle < 3 * M_PI / 2))
		{
			texture = data->map_data.img[EAST];
			color = get_pixel_color(texture, position_x, position_y);
			position_y = (ecart + (line.p1.y - start_y)) * texture.height / ray->lineH;
			if (position_y < 0)
				position_y = 0;
			if (position_y >= texture.height)
				position_y = texture.height - 1;
			position_x = ((int)(ray->y * texture.width) % gap) * texture.width / gap;
			if (position_x < 0)
				position_x = 0;
			if (position_x >= texture.width)
				position_x = texture.width - 1;
		}
		else
		{
			texture = data->map_data.img[SOUTH];
			color = get_pixel_color(texture, position_x, position_y);
			position_y = (ecart + (line.p1.y - start_y)) * texture.height / ray->lineH;
			if (position_y < 0)
				position_y = 0;
			if (position_y >= texture.height)
				position_y = texture.height - 1;
			position_x = ((int)(ray->x * texture.width) % gap) * texture.width / gap;
			if (position_x < 0)
				position_x = 0;
			if (position_x >= texture.width)
				position_x = texture.width - 1;
		}
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
	color = get_pixel_color(texture, position_x, position_y);
	my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
}
