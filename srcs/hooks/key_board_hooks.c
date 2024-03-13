/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:13:37 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/13 07:26:58 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_moving_press(int keycode, t_cub3D_data *data)
{
	if (keycode == W_KEY_CODE)
		data->player.point.pos_y -= 10;
	if (keycode == S_KEY_CODE)
		data->player.point.pos_y += 10;
	if (keycode == A_KEY_CODE)
		data->player.point.pos_x -= 10;
	if (keycode == D_KEY_CODE)
		data->player.point.pos_x += 10;
	cub3d(data);
	return (true);
}

bool	key_board_hooks(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 2, 1L << 0, handle_moving_press, data);
	return (true);
}
