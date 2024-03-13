/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_session.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:04:13 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 05:26:07 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	terminate_session(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 17, 0, handle_window_close, data);
	mlx_hook(data->window.address, 3, 1L << 1, handle_escape_press, data);
	return (EXIT_SUCCESS);
}

int	handle_escape_press(int keycode, t_cub3D_data *data)
{
	if (keycode == ESC_KEY_CODE)
	{
		mlx_destroy_image(data->window.mlx, data->img_data.img);
		mlx_destroy_window(data->window.mlx, data->window.address);
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
		destroy_map(data->map_data.map, 5);
		exit (0);
	}
	return (0);
}

int	handle_window_close(t_cub3D_data *data)
{
	mlx_destroy_image(data->window.mlx, data->img_data.img);
	mlx_destroy_window(data->window.mlx, data->window.address);
	mlx_destroy_display(data->window.mlx);
	free(data->window.mlx);
	destroy_map(data->map_data.map, 5);
	exit (0);
}
