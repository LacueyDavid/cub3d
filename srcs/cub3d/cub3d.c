/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 08:55:10 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_minimap(t_cub3D_data *data)
{
	data->map_data.minimap_wall_color[0] = 255;
	data->map_data.minimap_wall_color[1] = 255;
	data->map_data.minimap_wall_color[2] = 255;
}

int	cub3d(t_cub3D_data *data)
{
	init_minimap(data);
	reset_image(data);
	draw_minimap(data);
	draw_player(data);
	mlx_put_image_to_window(data->window.mlx,
		data->window.address, data->img_data.img, 0, 0);
	return (1);
}
