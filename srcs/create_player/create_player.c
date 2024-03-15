/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/14 15:36:11 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_player(t_player *player, t_map_data *map_data)
{
	player->size = 4;
	player->color[0] = 255;
	player->color[1] = 255;
	player->color[2] = 0;
	set_player_position(player, map_data);
	return (true);
}

void	set_player_position(t_player *player, t_map_data *map_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[y][x] == NORTH)
			{
				player->point.pos_x = (x + 1) * GAP;
				player->point.pos_y = (y + 1) * GAP;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub3D_data *data)
{
	int	x;
	int	y;

	x = data->player.point.pos_x - data->player.size;
	while (x <= data->player.point.pos_x + data->player.size)
	{
		y = data->player.point.pos_y - data->player.size;
		while (y <= data->player.point.pos_y + data->player.size)
		{
			my_mlx_pixel_put(&data->img_data, x, y,
				rgb_to_int(data->player.color));
			y++;
		}
		x++;
	}
}
