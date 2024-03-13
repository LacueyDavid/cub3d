/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 11:55:12 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:47:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_int(int color_rgb[3])
{
	return (color_rgb[0] << 16 | color_rgb[1] << 8 | color_rgb[2]);
}

static void	draw_player(t_cub3D_data *data)
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

void	draw_map_wall(t_cub3D_data *data, int x, int y)
{
	int	start_x;
	int	start_y;
	int	margin;
	int	gap;
	int	color[3];

	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	start_x = x;
	start_y = y;
	margin = WIDTH / 70;
	gap = WIDTH / 40;
	while (y < start_y + gap)
	{
		x = start_x;
		while (x < start_x + gap)
		{
			my_mlx_pixel_put(&data->img_data, y + margin, x + margin,
				rgb_to_int(color));
			x++;
		}
		y++;
	}
}

static void	draw_map(t_cub3D_data *data)
{
	int	x;
	int	y;
	int	gap;

	gap = WIDTH / 40;
	y = 0;
	while (y < data->map_data.width)
	{
		x = 0;
		while (x < data->map_data.height)
		{
			if (data->map_data.map[y][x] == WALL)
				draw_map_wall(data, y * gap, x * gap);
			x++;
		}
		y++;
	}
}

static bool	reset_image(t_cub3D_data *data)
{
	ft_bzero(data->img_data.address,
		WIDTH * HEIGHT * data->img_data.bits_per_pixel / 8);
	return (true);
}

int	cub3d(t_cub3D_data *data)
{
	reset_image(data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->window.mlx,
		data->window.address, data->img_data.img, 0, 0);
	return (1);
}
