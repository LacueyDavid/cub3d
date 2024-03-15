/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:43:52 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 10:21:10 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_wall(t_cub3D_data *data, int x, int y, int gap)
{
	int	start_x;
	int	start_y;
	int margin;

	start_x = x;
	start_y = y;
	margin = WIDTH / 70;
	while (y < start_y + gap)
	{
		x = start_x;
		while (x < start_x + gap)
		{
			my_mlx_pixel_put(&data->img_data, y + margin, x + margin,
				rgb_to_int(data->map_data.minimap_wall_color));
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub3D_data *data)
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	gap;
	t_map_enum	**map;

	y = 0;
	width = data->map_data.width;
	height = data->map_data.height;
	map = data->map_data.map;
	gap = (WIDTH / 4) / data->map_data.width;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == WALL)
				draw_minimap_wall(data, y * gap, x * gap, gap);
			x++;
		}
		y++;
	}
}
