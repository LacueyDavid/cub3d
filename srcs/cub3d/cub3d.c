/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 15:51:47 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	reset_image(t_cub3D_data *data)
{
	ft_bzero(data->img_data.address,
		WIDTH * HEIGHT * data->img_data.bits_per_pixel / 8);
	return (true);
}

void	draw_player_direction(t_cub3D_data *data)
{
	t_line	line;

	line.p1.x = (int)data->player.position.x;
	line.p1.y = (int)data->player.position.y;
	line.p2.x = (int)data->player.position.x + data->player.delta_x * 10;
	line.p2.y = (int)data->player.position.y + data->player.delta_y * 10;
	rasterization(line, &data->img_data,
		rgb_to_int(data->player.color));
}

// rasterization prend une line qui est deux point, chaque point est une
// coordonnée x et y en /!\ INT /!\, pas en float!
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
	draw_player_direction(data);
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
