/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_first_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:17:17 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/26 05:23:52 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "parser.h"
#include "player.h"

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
	int	center;

	center = (map_data->gap / 2) - 1;
	y = 0;
	gap = map_data->gap;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (is_cardinal_point(map_data->map[y][x]))
			{
				player->position.x = x * gap + center;
				player->position.y = y * gap + center;
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
		player->angle = 1 * d_pi;
	else if (player->orientation == SOUTH)
		player->angle = 3 * d_pi;
	else if (player->orientation == WEST)
		player->angle = M_PI;
	else if (player->orientation == EAST)
		player->angle = 0; //tester avec un depart a l'est
	player->delta_x = cos(player->angle);
	player->delta_y = -sin(player->angle);
}
