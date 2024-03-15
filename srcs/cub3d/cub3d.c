/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 15:10:40 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	reset_image(t_cub3D_data *data)
{
	ft_bzero(data->img_data.address,
		WIDTH * HEIGHT * data->img_data.bits_per_pixel / 8);
	return (true);
}

t_point	define_direction(t_line line)
{
	t_point	direction;

	if (line.p1.x < line.p2.x)
		direction.x = 1;
	else
		direction.x = -1;
	if (line.p1.y < line.p2.y)
		direction.y = 1;
	else
		direction.y = -1;
	return (direction);
}

void	rasterization(t_line line, t_img_data *img, int color)
{
	int		error;
	int		err2;
	t_point	diff;
	t_point	direction;

	direction = define_direction(line);
	diff.x = abs((int)line.p2.x - (int)line.p1.x);
	diff.y = -abs((int)line.p2.y - (int)line.p1.y);
	error = diff.x + diff.y;
	while (line.p1.x != line.p2.x || line.p1.y != line.p2.y)
	{
		my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
		err2 = 2 * error;
		if (err2 >= diff.y)
		{
			error += diff.y;
			line.p1.x += direction.x;
		}
		if (err2 <= diff.x)
		{
			error += diff.x;
			line.p1.y += direction.y;
		}
	}
	my_mlx_pixel_put(img, line.p1.x, line.p1.y, color);
}

void	draw_player(t_cub3D_data *data)
{
	float	x;
	float	y;
	int		player_size;

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
	// rasterization prend une line qui est deux point, chaque point est une
	// coordonnée x et y en /!\ INT /!\, pas en float!
	t_line line;
	line.p1.x = (int)data->player.position.x;
	line.p1.y = (int)data->player.position.y;
	line.p2.x = (int)data->player.position.x + data->player.delta_x * 10;
	line.p2.y = (int)data->player.position.y + data->player.delta_y * 10;
	rasterization(line, &data->img_data,
		rgb_to_int(data->player.color));
}

int	cub3d(t_cub3D_data *data)
{
	reset_image(data);
	draw_minimap(data);
	draw_player(data);
	mlx_put_image_to_window(data->window.mlx,
							data->window.address, data->img_data.img, 0, 0);
	return (1);
}
