/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/18 14:19:30 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "mlx.h"

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

// la fonction reset_image va surement disparaitre plus tard
int	cub3d(t_cub3D_data *data)
{
	reset_image(&data->img_data);
	draw_minimap(data);
	draw_player(data->player, data->img_data);
	mlx_put_image_to_window(data->window.mlx,
		data->window.address, data->img_data.img, 0, 0);
	return (1);
}
