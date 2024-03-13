/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 05:19:58 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:47:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(int color_rgb[3])
{
	return (color_rgb[0] << 16 | color_rgb[1] << 8 | color_rgb[2]);
}

void	drawplayer(t_cub3D_data *data)
{
	int	x;
	int	y;

	x = data->player.point.pos_x - data->player.size;
	while (x <= data->player.point.pos_x + data->player.size)
	{
		y = data->player.point.pos_y - data->player.size;
		while (y <= data->player.point.pos_y + data->player.size)
		{
			my_mlx_pixel_put(&data->img_data, x, y, rgb_to_int(data->player.color));
			y++;
		}
		x++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

bool	reset_image(t_cub3D_data *data)
{
	ft_bzero(data->img_data.address,
		WIDTH * HEIGHT * data->img_data.bits_per_pixel / 8);
	return (true);
}

int	cub3d(t_cub3D_data *data)
{
	reset_image(data);
	drawplayer(data);
	mlx_put_image_to_window(data->window.mlx, data->window.address, data->img_data.img, 0, 0);
	return (1);
}
