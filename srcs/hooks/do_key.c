/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:20:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 15:40:57 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	do_w_key(t_cub3D_data *data)
{
	data->player.position.x += data->player.delta_x;
	data->player.position.y += data->player.delta_y;
}

static void	do_s_key(t_cub3D_data *data)
{
	data->player.position.x -= data->player.delta_x;
	data->player.position.y -= data->player.delta_y;
}

static void	do_a_key(t_cub3D_data *data)
{
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += (2 * M_PI);
	data->player.delta_x = cos(data->player.angle) * 4;
	data->player.delta_y = sin(data->player.angle) * 4;
}

static void	do_d_key(t_cub3D_data *data)
{
	data->player.angle += 0.1;
	if (data->player.angle > 2 * M_PI)
		data->player.angle -= (2 * M_PI);
	data->player.delta_x = cos(data->player.angle) * 4;
	data->player.delta_y = sin(data->player.angle) * 4;
}

void	do_key(t_cub3D_data *data, int keycode)
{
	if (keycode == W_KEY_CODE)
		do_w_key(data);
	if (keycode == S_KEY_CODE)
		do_s_key(data);
	if (keycode == A_KEY_CODE)
		do_a_key(data);
	if (keycode == D_KEY_CODE)
		do_d_key(data);
}
