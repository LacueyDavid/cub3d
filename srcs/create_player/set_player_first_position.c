/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_first_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:17:17 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/18 13:45:34 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "parser.h"
#include "player.h"
#include "cub3d_useful_values.h"

static bool	is_cardinal_point(t_map_enum map_enum)
{
	return (map_enum == NORTH || map_enum == SOUTH
		|| map_enum == EAST || map_enum == WEST);
}

void	set_first_player_position(t_player *player, t_map_data *map_data)
{
	int	x;
	int	y;
	int	gap;
	int	margin;

	y = 0;
	gap = map_data->gap;
	margin = WIDTH / 70;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (is_cardinal_point(map_data->map[y][x]))
			{
				player->position.x = (x + 1) * gap + margin - (gap / 2) - 1;
				player->position.y = (y + 1) * gap + margin - (gap / 2) - 1;
				player->orientation = map_data->map[y][x];
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_player_orientation(t_player *player)
{
	float	d_pi;

	d_pi = M_PI / 2;
	if (player->orientation == NORTH)
		player->angle = 3 * d_pi;
	else if (player->orientation == SOUTH)
		player->angle = d_pi;
	else if (player->orientation == WEST)
		player->angle = M_PI;
	else if (player->orientation == EAST)
		player->angle = 0;
	player->delta_x = cos(player->angle) * 4;
	player->delta_y = sin(player->angle) * 4;
}
