/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:18:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/29 14:40:25 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"

static void do_w_key(t_cub3D_data *data, t_handle_walls *handle_walls)
{
	if (data->key.w )
	{
		if (data->map_data.map[handle_walls->ipy][handle_walls->ipx_add_xo] != WALL)
		{
			data->player.position.x += data->player.delta_x * data->player.speed;
		}
		if (data->map_data.map[handle_walls->ipy_add_yo][handle_walls->ipx] != WALL)
		{
			data->player.position.y += data->player.delta_y * data->player.speed;
		}
	}
}

static void do_s_key(t_cub3D_data *data, t_handle_walls *handle_walls)
{
	if (data->key.s)
	{
		if (data->map_data.map[handle_walls->ipy][handle_walls->ipx_sub_xo] != WALL)
		{
			data->player.position.x -= data->player.delta_x * data->player.speed;
		}
		if (data->map_data.map[handle_walls->ipy_sub_yo][handle_walls->ipx] != WALL)
		{
			data->player.position.y -= data->player.delta_y * data->player.speed;
		}
	}
}

static void do_a_key(t_cub3D_data *data, t_handle_walls *handle_walls)
{
	if (data->key.a)
	{
		if (data->map_data.map[handle_walls->ipy][handle_walls->ipx_add_xod] != WALL)
		{
			data->player.position.x += data->player.delta_y * data->player.speed;
		}
		if (data->map_data.map[handle_walls->ipy_sub_yod][handle_walls->ipx] != WALL)
		{
			data->player.position.y -= data->player.delta_x * data->player.speed;
		}
	}
}

static void do_d_key(t_cub3D_data *data, t_handle_walls *handle_walls)
{
	if (data->key.d)
	{
		if (data->map_data.map[handle_walls->ipy][handle_walls->ipx_sub_xod] != WALL)
		{
			data->player.position.x -= data->player.delta_y * data->player.speed;
		}
		if (data->map_data.map[handle_walls->ipy_add_yod][handle_walls->ipx] != WALL)
		{
			data->player.position.y += data->player.delta_x * data->player.speed;
		}
	}
}

void	do_movement_keys(t_cub3D_data *data)
{
	t_handle_walls	handle_walls;

	init_handle_walls(&handle_walls, data);
	do_w_key(data, &handle_walls);
	do_s_key(data, &handle_walls);
	do_a_key(data, &handle_walls);
	do_d_key(data, &handle_walls);
	do_arrow_left_key(data);
	do_arrow_right_key(data);
}
