/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textured_rasterization.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:46:30 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_useful_values.h"
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

static void	calculate_next_coordinate(t_line *line, t_rasterization *ras)
{
	ras->err2 = 2 * ras->error;
	if (ras->err2 >= ras->diff.y)
	{
		ras->error += ras->diff.y;
		line->p1.x += ras->direction.x;
	}
	if (ras->err2 <= ras->diff.x)
	{
		ras->error += ras->diff.x;
		line->p1.y += ras->direction.y;
	}
}

static void	init_textured_rasterization(t_pixel_extractor *extractor,
			t_line line, t_ray *ray, t_rasterization *ras)
{
	extractor->color = 0;
	extractor->position_x = 0;
	extractor->position_y = 0;
	extractor->start_y = line.p1.y;
	extractor->ecart = ray->line_height / 2 - HEIGHT / 2;
	if (extractor->ecart < 0)
		extractor->ecart = 0;
	ras->direction = define_direction(line);
	ras->diff.x = abs((int)line.p2.x - (int)line.p1.x);
	ras->diff.y = -abs((int)line.p2.y - (int)line.p1.y);
	ras->error = ras->diff.x + ras->diff.y;
}

void	textured_rasterization(t_line line,
		t_img_data *img, t_ray *ray, t_cub3d_data *data)
{
	t_rasterization		ras;
	t_pixel_extractor	extractor;

	extractor.map_gap = data->map_data.gap;
	init_textured_rasterization(&extractor, line, ray, &ras);
	while (line.p1.x != line.p2.x || line.p1.y != line.p2.y)
	{
		extractor.line_p1_y = line.p1.y;
		choose_pixel_texture(ray, &extractor, data);
		my_mlx_pixel_put(img, line.p1.x, line.p1.y, extractor.color);
		calculate_next_coordinate(&line, &ras);
	}
	extractor.color = get_pixel_color(extractor.texture, extractor.position_x,
			extractor.position_y);
	my_mlx_pixel_put(img, line.p1.x, line.p1.y, extractor.color);
}
