/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:01:53 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 11:04:45 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include "cub3d_useful_values.h"

void	reset_player(t_cub3D_data *data)
{
	if (data->key.r)
	{
		data->player.position.x = data->player.first_position.x;
		data->player.position.y = data->player.first_position.y;
		data->player.angle = data->player.first_angle;
		data->player.delta_x = cos(data->player.angle);
		data->player.delta_y = -sin(data->player.angle);
	}
}

void	do_shift_key(t_cub3D_data *data)
{
	if (data->key.shift)
		data->player.speed = (float)data->map_data.gap / (float)SPRINT_SPEED;
	else
		data->player.speed = (float)data->map_data.gap / (float)SPEED;
}
