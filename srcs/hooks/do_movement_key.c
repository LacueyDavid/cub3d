/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_movement_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:36:07 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/29 14:43:59 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"
#include <math.h>

void init_handle_walls(t_handle_walls *handle_walls, t_cub3D_data *data)
{
	int gap;
	int pos_x;
	int pos_y;

	gap = data->map_data.gap;
	pos_x = data->player.position.x;
	pos_y = data->player.position.y;
	if (data->player.delta_x < 0)
		handle_walls->x_offset = -gap / 4;
	else
		handle_walls->x_offset = gap / 4;
	if (data->player.delta_y < 0)
		handle_walls->y_offset = -gap / 4;
	else
		handle_walls->y_offset = gap / 4;
	handle_walls->ipx_add_xo = (pos_x + handle_walls->x_offset) / gap;
	handle_walls->ipy_add_yo = (pos_y + handle_walls->y_offset) / gap;
	handle_walls->ipx_sub_xo = (pos_x - handle_walls->x_offset) / gap;
	handle_walls->ipy_sub_yo = (pos_y - handle_walls->y_offset) / gap;
	handle_walls->ipx_add_xod = (pos_x + handle_walls->y_offset) / gap;
	handle_walls->ipy_add_yod = (pos_y + handle_walls->x_offset) / gap;
	handle_walls->ipx_sub_xod = (pos_x - handle_walls->y_offset) / gap;
	handle_walls->ipy_sub_yod = (pos_y - handle_walls->x_offset) / gap;
	handle_walls->ipx = (int)pos_x / gap;
	handle_walls->ipy = (int)pos_y / gap;
}

void do_arrow_left_key(t_cub3D_data *data)
{
	if (data->key.arrow_left)
	{
		data->player.angle += data->player.rotate_speed;
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= (2 * M_PI);
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
}

void do_arrow_right_key(t_cub3D_data *data)
{
	if (data->key.arrow_right)
	{
		data->player.angle -= data->player.rotate_speed;
		if (data->player.angle < 0)
			data->player.angle += (2 * M_PI);
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
}
