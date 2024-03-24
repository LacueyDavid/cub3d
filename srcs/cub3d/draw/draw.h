/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:23:31 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/21 10:57:30 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "image_data.h"
# include "cub3d.h"
# include "player.h"

typedef struct ray
{
	float negative_invert_tan;
	float negative_tan;
	float angle;
	float x;
	float y;
	float vx;
	float vy;
	float x_offset;
	float y_offset;
	float numbers;
	int depth_of_field;
} t_ray;

void	rasterization(t_line line, t_img_data *img, int color);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
bool	reset_image(t_img_data *img_data);
void	draw_minimap(t_cub3D_data *data);
void	draw_player(const t_player player, t_img_data img_data);

#endif
