/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 10:20:33 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_player(t_player *player, t_map_data *map_data)
{
	int two_time_smaller_than_one_block;

	two_time_smaller_than_one_block = (WIDTH / 4) / map_data->width / 2;
	player->size = two_time_smaller_than_one_block;
	player->color[0] = 255;
	player->color[1] = 255;
	player->color[2] = 0;
	set_player_position(player, map_data);
	return (true);
}

bool	is_a_cardinal_point(t_map_enum map_enum)
{
	return (map_enum == NORTH || map_enum == SOUTH
		|| map_enum == EAST || map_enum == WEST);
}

bool	choose_position_and_orientation(t_player *player, t_map_data *map_data,
						int x, int y)
{
	int gap;
	int margin;

	gap = (WIDTH / 4) / map_data->width;
	margin = WIDTH / 70;
	if (is_a_cardinal_point(map_data->map[y][x]))
	{
		player->position.x = (x + 1) * gap + margin - (gap / 2) - 1;
		player->position.y = (y + 1) * gap + margin - (gap / 2) - 1;
		player->orientation = map_data->map[y][x];
		return (true);
	}
	return (false);
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
			if (choose_position_and_orientation(player, map_data, x, y))
				return ;
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub3D_data *data)
{
	int	x;
	int	y;
	int	player_size;

	player_size = data->player.size;
	x = data->player.position.x - player_size / 2;
	while (x <= data->player.position.x + player_size / 2)
	{
		y = data->player.position.y - player_size / 2;
		while (y <= data->player.position.y + player_size / 2)
		{
			my_mlx_pixel_put(&data->img_data, x, y,
				rgb_to_int(data->player.color));
			y++;
		}
		x++;
	}
}
