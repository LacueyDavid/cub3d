/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:13:37 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/05 12:14:54 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"
#include "cub3d_useful_values.h"
#include "mlx.h"

void	ensure_player_is_in_map(t_cub3D_data *data)
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
	do_key(data, keycode);
	ensure_player_is_in_map(data);
	cub3d(data);
	return (true);
}

bool	key_board_hooks(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 2, 1L << 0, handle_moving_press, data);
	return (true);
}
