/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 12:54:08 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:47:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d(t_cub3D_data *data)
{
	reset_image(data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->window.mlx,
		data->window.address, data->img_data.img, 0, 0);
	return (1);
}
