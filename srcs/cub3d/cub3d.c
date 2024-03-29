/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/29 08:18:39 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "mlx.h"
#include "libft_and_utils.h"
#include <math.h>

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

static void	ensure_player_is_in_map(t_cub3D_data *data)
{
	int	one_block;

	one_block = data->map_data.gap;
	if (data->player.position.x < 0)
		data->player.position.x = 0;
	if (data->player.position.x > one_block * data->map_data.width)
		data->player.position.x = one_block * data->map_data.width;
	if (data->player.position.y < 0)
		data->player.position.y = 0;
	if (data->player.position.y > one_block * data->map_data.height)
		data->player.position.y = one_block * data->map_data.height;
}


void	key_gestion(t_cub3D_data *data)
{
	if (data->key.r)
	{
		data->player.position.x = data->player.first_position.x;
		data->player.position.y = data->player.first_position.y;
		data->player.angle = data->player.first_angle;
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
	if (data->key.shift)
		data->player.speed = (float)data->map_data.gap / 25;
	else
		data->player.speed = (float)data->map_data.gap / 75;
	// may add fps for bonus but need time function
	int x_offset;
	int y_offset;
	int ipx;
	int ipy;
	int ipx_add_xo;
	int ipy_add_yo;
	int ipx_sub_xo;
	int ipy_sub_yo;
	int ipx_add_xod;
	int ipy_add_yod;
	int ipx_sub_xod;
	int ipy_sub_yod;
	if (data->player.delta_x < 0)
		x_offset = -data->map_data.gap / 4;
	else
		x_offset = data->map_data.gap / 4;
	if (data->player.delta_y < 0)
		y_offset = -data->map_data.gap / 4;
	else
		y_offset = data->map_data.gap / 4;
	ipx_add_xo = (data->player.position.x + x_offset) / data->map_data.gap;
	ipy_add_yo = (data->player.position.y + y_offset ) / data->map_data.gap;
	ipx_sub_xo = (data->player.position.x - x_offset) / data->map_data.gap;
	ipy_sub_yo = (data->player.position.y - y_offset ) / data->map_data.gap;
	ipx_add_xod = (data->player.position.x + y_offset) / data->map_data.gap;
	ipy_add_yod = (data->player.position.y + x_offset ) / data->map_data.gap;
	ipx_sub_xod = (data->player.position.x - y_offset) / data->map_data.gap;
	ipy_sub_yod = (data->player.position.y - x_offset ) / data->map_data.gap;
	ipx = (int)data->player.position.x / data->map_data.gap;
	ipy = (int)data->player.position.y / data->map_data.gap;
	if (data->key.w )
	{
		if (data->map_data.map[ipy][ipx_add_xo] != WALL)
		{
			data->player.position.x += data->player.delta_x * data->player.speed;
		}
		if (data->map_data.map[ipy_add_yo][ipx] != WALL)
		{
			data->player.position.y += data->player.delta_y * data->player.speed;
		}
	}
	if (data->key.s)
	{
		if (data->map_data.map[ipy][ipx_sub_xo] != WALL)
		{
			data->player.position.x -= data->player.delta_x * data->player.speed;
		}
		if (data->map_data.map[ipy_sub_yo][ipx] != WALL)
		{
			data->player.position.y -= data->player.delta_y * data->player.speed;
		}
	}
	if (data->key.a)
	{
		if (data->map_data.map[ipy][ipx_add_xod] != WALL)
		{
			data->player.position.x += data->player.delta_y * data->player.speed;
		}
		if (data->map_data.map[ipy_sub_yod][ipx] != WALL)
		{
			data->player.position.y -= data->player.delta_x * data->player.speed;
		}
	}
	if (data->key.d)
	{
		if (data->map_data.map[ipy][ipx_sub_xod] != WALL)
		{
			data->player.position.x -= data->player.delta_y * data->player.speed;
		}
		if (data->map_data.map[ipy_add_yod][ipx] != WALL)
		{
			data->player.position.y += data->player.delta_x * data->player.speed;
		}
	}
	if (data->key.arrow_left)
	{
		data->player.angle += data->player.rotate_speed;
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= (2 * M_PI);
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
	if (data->key.arrow_right)
	{
		data->player.angle -= data->player.rotate_speed;
		if (data->player.angle < 0)
			data->player.angle += (2 * M_PI);
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
	ensure_player_is_in_map(data);
}

// la fonction reset_image va surement disparaitre plus tard
int	cub3d(t_cub3D_data *data)
{
	key_gestion(data);
	reset_image(&data->img_data);
	draw_rays(data);
	if (data->key.tab)
	{
		draw_minimap(data);
		draw_player(data->player, data->img_data);
	}
	mlx_put_image_to_window(data->window.mlx,
							data->window.address, data->img_data.img, 0, 0);
	mlx_do_sync(data->window.mlx);
	return (1);
}
