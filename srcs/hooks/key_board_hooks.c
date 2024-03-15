/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:13:37 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 14:43:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ensure_player_is_in_map(t_cub3D_data *data)
{
	int	one_block;
	int	margin;

	margin = WIDTH / 70;
	one_block = data->map_data.gap;
	if (data->player.position.x < 0 + margin)
		data->player.position.x = 0 + margin;
	if (data->player.position.x > one_block * data->map_data.width + margin)
		data->player.position.x = one_block * data->map_data.width + margin;
	if (data->player.position.y < 0 + margin)
		data->player.position.y = 0 + margin;
	if (data->player.position.y > one_block * data->map_data.height + margin)
		data->player.position.y = one_block * data->map_data.height + margin;
}

int	handle_moving_press(int keycode, t_cub3D_data *data)
{
	if (keycode == W_KEY_CODE)
	{
		data->player.position.x += data->player.delta_x;
		data->player.position.y += data->player.delta_y;
	}
	if (keycode == S_KEY_CODE)
	{
		data->player.position.x -= data->player.delta_x;
		data->player.position.y -= data->player.delta_y;
	}
	if (keycode == A_KEY_CODE)
	{
		data->player.angle -= 0.1;
		if (data->player.angle < 0)
			data->player.angle += (2 * M_PI);
		data->player.delta_x = cos(data->player.angle) * 4;
		data->player.delta_y = sin(data->player.angle) * 4;
	}
	if (keycode == D_KEY_CODE)
	{
		data->player.angle += 0.1;
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= (2 * M_PI);
		data->player.delta_x = cos(data->player.angle) * 4;
		data->player.delta_y = sin(data->player.angle) * 4;
	}
	ensure_player_is_in_map(data);
	cub3d(data);
	return (true);
}

bool	key_board_hooks(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 2, 1L << 0, handle_moving_press, data);
	return (true);
}
