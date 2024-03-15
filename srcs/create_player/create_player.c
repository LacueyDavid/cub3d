/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 15:35:04 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
