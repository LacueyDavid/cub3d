/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:13:37 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/26 05:13:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"
#include "cub3d_useful_values.h"
#include "mlx.h"

static void	ensure_player_is_in_map(t_cub3D_data *data)
{
	int	one_block;

	one_block = data->map_data.gap;
	if (data->player.position.x < 0 )
		data->player.position.x = 0 ;
	if (data->player.position.x > one_block * data->map_data.width )
		data->player.position.x = one_block * data->map_data.width ;
	if (data->player.position.y < 0 )
		data->player.position.y = 0 ;
	if (data->player.position.y > one_block * data->map_data.height)
		data->player.position.y = one_block * data->map_data.height;
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
