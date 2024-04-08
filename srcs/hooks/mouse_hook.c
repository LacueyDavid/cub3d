/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:43:43 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/08 19:24:27 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "hooks.h"
#include "mlx.h"
#include <math.h>
#include <X11/Xlib.h>

void	do_alt_key(t_cub3D_data *data)
{
	if (data->window.mouse_integ)
	{
		mlx_mouse_show(data->window.mlx, data->window.address);
		data->window.mouse_integ = 0;
	}
	else
	{
		mlx_mouse_hide(data->window.mlx, data->window.address);
		data->window.mouse_integ = 1;
	}
}

bool	reset_mouse_position(t_cub3D_data *data, int c_x, int c_y, int *prev)
{
	int	x;
	int	y;

	x = WIDTH / 2;
	y = HEIGHT / 2;
	if (!data->window.mouse_integ)
		return (false);
	if (c_x >= WIDTH - 300 || c_x <= 300
		|| c_y >= HEIGHT - 200 || c_y <= 200)
	{
		prev[0] = x;
		prev[1] = y;
		mlx_mouse_move(data->window.mlx, data->window.address, x, y);
		return (true);
	}
	return (false);
}

int	mouse_handler(int x, int y, t_cub3D_data *data)
{
	double			delta_x;
	static int		prev_pos[2];
	static double	accumulated_delta_x;
	bool			mouse_reset;
	double			rotation_speed;

	prev_pos[0] = -1;
	prev_pos[1] = -1;
	accumulated_delta_x = 0.0;
	mouse_reset = false;
	if (prev_pos[0] != -1 && prev_pos[1] != -1 && data->window.mouse_integ)
	{
		mouse_reset = reset_mouse_position(data, x, y, prev_pos);
		if (mouse_reset == false)
			delta_x = x - prev_pos[0];
		else
			delta_x = 0;
		accumulated_delta_x += fabs(delta_x);
		rotation_speed = BASE + (accumulated_delta_x / MAX) * SCALE;
		data->player.angle -= delta_x * rotation_speed;
		while (data->player.angle >= 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		while (data->player.angle < 0)
			data->player.angle += 2 * M_PI;
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
		ensure_player_is_in_map(data);
	}
	if (mouse_reset == false)
	{
		prev_pos[0] = x;
		prev_pos[1] = y;
	}
	return (0);
}

bool	mouse_hook(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 6, PointerMotionMask, mouse_handler, data);
	return (true);
}
