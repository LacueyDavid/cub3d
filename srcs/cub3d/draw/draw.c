/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:15:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/18 14:16:58 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d_useful_values.h"

static void	draw_player_direction(t_player player, t_img_data img_data)
{
	t_line	line;

	line.p1.x = player.position.x;
	line.p1.y = player.position.y;
	line.p2.x = player.position.x + player.delta_x * 10;
	line.p2.y = player.position.y + player.delta_y * 10;
	rasterization(line, &img_data, rgb_to_int(player.color));
}

static void	draw_player_sprite(const t_player player, t_img_data img_data)
{
	int	x;
	int	y;
	int	begin_y;

	x = player.position.x - player.size / 2;
	y = player.position.y - player.size / 2;
	begin_y = player.position.y - player.size / 2;
	while (x <= player.position.x + player.size / 2)
	{
		y = begin_y;
		while (y <= player.position.y + player.size / 2)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
				my_mlx_pixel_put(&img_data, x, y,
					rgb_to_int(player.color));
			y++;
		}
		x++;
	}
}

void	draw_player(const t_player player, t_img_data img_data)
{
	draw_player_sprite(player, img_data);
	draw_player_direction(player, img_data);
}
