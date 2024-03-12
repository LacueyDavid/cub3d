/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:57:28 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 15:00:21 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:52:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_window(t_window *window, t_img_data *img_data)
{
	window->mlx = mlx_init();
	if (!(window->mlx))
		return (false);
	window->address = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!(window->address))
		return (false);



	img_data->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	if (!(img_data->img))
		return (false);
	img_data->address = mlx_get_data_addr(img_data->img,
			&img_data->bits_per_pixel, &img_data->line_length,
			&img_data->endian);
	if (!(img_data->address))
		return (false);
	return (true);
}
