/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:43:52 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/14 15:38:26 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_map_wall(t_cub3D_data *data, int x, int y)
{
	int	start_x;
	int	start_y;

	start_x = x;
	start_y = y;
	while (y < start_y + GAP)
	{
		x = start_x;
		while (x < start_x + GAP)
		{
			my_mlx_pixel_put(&data->img_data, y + MARGIN, x + MARGIN,
				rgb_to_int(data->map_data.minimap_wall_color));
			x++;
		}
		y++;
	}
}

void	draw_map(t_cub3D_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_data.height)
	{
		x = 0;
		while (x < data->map_data.width)
		{
			if (data->map_data.map[y][x] == WALL)
				draw_map_wall(data, y * GAP, x * GAP);
			x++;
		}
		y++;
	}
}
