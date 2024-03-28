/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:43:52 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 02:07:18 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_useful_values.h"

void	set_minimap_colors(t_map_data *map_data)
{
	map_data->minimap_wall_color.r = 255;
	map_data->minimap_wall_color.g = 255;
	map_data->minimap_wall_color.b = 255;
}

static void	draw_minimap_wall(t_cub3D_data *data, int x, int y, int gap)
{
	int	start_x;
	int	start_y;

	start_x = x;
	start_y = y;
	while (y < start_y + gap)
	{
		x = start_x;
		while (x < start_x + gap)
		{
			my_mlx_pixel_put(&data->img_data, y, x,
				rgb_to_int(data->map_data.minimap_wall_color));
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub3D_data *data)
{
	int			x;
	int			y;
	int			gap;
	t_map_enum	**map;

	y = 0;
	map = data->map_data.map;
	gap = data->map_data.gap;
	while (y < data->map_data.height)
	{
		x = 0;
		while (x < data->map_data.width)
		{
			if (map[y][x] == WALL)
				draw_minimap_wall(data, y * gap, x * gap, gap);
			x++;
		}
		y++;
	}
}
