/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:21:41 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"
#include <stdio.h>

void	draw_minimap_2d_ray(t_cub3d_data *data, t_ray *ray)
{
	t_line		line;
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
