/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 15:07:01 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_cardinal_point(t_map_enum map_enum)
{
	return (map_enum == NORTH || map_enum == SOUTH
		|| map_enum == EAST || map_enum == WEST);
}

static void	set_first_player_position(t_player *player, t_map_data *map_data)
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
	float d_pi;

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

void	set_player_size(t_player *player, t_map_data *map_data)
{
	int	two_time_smaller_than_one_block;

	two_time_smaller_than_one_block = map_data->gap / 2;
	player->size = two_time_smaller_than_one_block;
}

void	set_player_color(t_player *player)
{
	player->color[0] = 255;
	player->color[1] = 0;
	player->color[2] = 0;
}

bool	create_player(t_player *player, t_map_data *map_data)
{
	set_player_size(player, map_data);
	set_player_color(player);
	set_first_player_position(player, map_data);
	set_player_orientation(player);
	return (true);
}
