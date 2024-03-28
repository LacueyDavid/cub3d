/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:12:49 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 07:59:57 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_size(t_player *player, t_map_data *map_data)
{
	player->size = map_data->gap / 4;
}

void	set_player_color(t_player *player)
{
	player->color.r = 255;
	player->color.g = 0;
	player->color.b = 0;
}

bool	create_player(t_player *player, t_map_data *map_data)
{
	player->speed = (float)map_data->gap / 75;
	player->rotate_speed = (float)map_data->gap / 400;
	set_player_size(player, map_data);
	set_player_color(player);
	set_first_player_position(player, map_data);
	set_player_orientation(player);
	return (true);
}
