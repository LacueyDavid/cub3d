/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:18:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 11:33:14 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"

static void	do_w_key(t_cub3D_data *d, t_handle_walls *hw)
{
	if (d->key.w)
	{
		if (d->map_data.map[hw->ipy][hw->ipx_add_xo] != WALL)
		{
			d->player.position.x += d->player.delta_x * d->player.speed;
		}
		if (d->map_data.map[hw->ipy_add_yo][hw->ipx] != WALL)
		{
			d->player.position.y += d->player.delta_y * d->player.speed;
		}
	}
}

static void	do_s_key(t_cub3D_data *d, t_handle_walls *hw)
{
	if (d->key.s)
	{
		if (d->map_data.map[hw->ipy][hw->ipx_sub_xo] != WALL)
		{
			d->player.position.x -= d->player.delta_x * d->player.speed;
		}
		if (d->map_data.map[hw->ipy_sub_yo][hw->ipx] != WALL)
		{
			d->player.position.y -= d->player.delta_y * d->player.speed;
		}
	}
}

static void	do_a_key(t_cub3D_data *d, t_handle_walls *hw)
{
	if (d->key.a)
	{
		if (d->map_data.map[hw->ipy][hw->ipx_add_xod] != WALL)
		{
			d->player.position.x += d->player.delta_y * d->player.speed;
		}
		if (d->map_data.map[hw->ipy_sub_yod][hw->ipx] != WALL)
		{
			d->player.position.y -= d->player.delta_x * d->player.speed;
		}
	}
}

static void	do_d_key(t_cub3D_data *d, t_handle_walls *hw)
{
	if (d->key.d)
	{
		if (d->map_data.map[hw->ipy][hw->ipx_sub_xod] != WALL)
		{
			d->player.position.x -= d->player.delta_y * d->player.speed;
		}
		if (d->map_data.map[hw->ipy_add_yod][hw->ipx] != WALL)
		{
			d->player.position.y += d->player.delta_x * d->player.speed;
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
