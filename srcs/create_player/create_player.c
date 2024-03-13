/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/13 11:48:22 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_position(t_player *player, t_map_data *map_data)
{
	int	x;
	int	y;
	int	gap;

	gap = WIDTH / 40;
	y = 0;
	while (y < map_data->width)
	{
		x = 0;
		while (x < map_data->height)
		{
			if (map_data->map[y][x] == NORTH)
			{
				player->point.pos_x = (x + 1) * gap;
				player->point.pos_y = (y + 1) * gap;
				return ;
			}
			x++;
		}
		y++;
	}
}

bool	create_player(t_player *player, t_map_data *map_data)
{
	player->point.pos_x = 300;
	player->point.pos_y = 300;
	player->size = 4;
	player->color[0] = 255;
	player->color[1] = 255;
	player->color[2] = 0;
	set_player_position(player, map_data);
	return (true);
}
