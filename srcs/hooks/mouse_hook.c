/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:43:43 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/09 10:02:08 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "hooks.h"
#include "mlx.h"
#include <math.h>
#include <stdbool.h>
#include <X11/Xlib.h>

void	do_alt_key(t_cub3D_data *data)
{
	if (data->window.mouse_integ)
	{
		mlx_mouse_show(data->window.mlx, data->window.address);
		data->window.mouse_integ = false;
	}
	else
	{
		mlx_mouse_hide(data->window.mlx, data->window.address);
		data->window.mouse_integ = true;
	}
}

bool	reset_mouse_position(t_cub3D_data *data, int mouse_x, int mouse_y, t_mouse *mouse)
{
	int	center_x;
	int	center_y;

	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	if (!data->window.mouse_integ)
		return (false);
	if (mouse_x >= WIDTH - 300 || mouse_x <= 300
		|| mouse_y >= HEIGHT - 200 || mouse_y <= 200)
	{
		mouse->prev_x = center_x;
		mouse->prev_y = center_y;
		mlx_mouse_move(data->window.mlx, data->window.address, center_x, center_y);
		return (true);
	}
	return (false);
}

static void	get_previous_positions(int x, int y, t_mouse *mouse)
{
	if (mouse->mouse_reset == false)
	{
		mouse->prev_x = x;
		mouse->prev_y = y;
	}
}

int	mouse_handler(int x, int y, t_cub3D_data *data)
{
	t_mouse	*mouse;

	mouse = &data->mouse;
	mouse->mouse_reset = false;
	if (mouse->prev_x != -1 && mouse->prev_y != -1 && data->window.mouse_integ)
	{
		mouse->mouse_reset = reset_mouse_position(data, x, y, mouse);
		if (mouse->mouse_reset == false)
			mouse->delta_x = x - mouse->prev_x;
		else
			mouse->delta_x = 0;
		mouse->accumulated_delta_x += fabs(mouse->delta_x);
		mouse->rotation_speed = BASE + (mouse->accumulated_delta_x / MAX) * SCALE;
		data->player.angle -= mouse->delta_x * mouse->rotation_speed;
		while (data->player.angle >= 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		while (data->player.angle < 0)
			data->player.angle += 2 * M_PI;
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
	get_previous_positions(x, y, mouse);
	return (0);
}

bool	mouse_hook(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 6, PointerMotionMask, mouse_handler, data);
	return (true);
}
