/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_session.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:04:13 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 15:11:58 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	terminate_session(t_cub3D_data *data)
{
	mlx_destroy_image(data->window.mlx, data->img_data.img);
	mlx_hook(data->window.address, 17, 0, handle_window_close, data);
	mlx_key_hook(data->window.address, handle_key_press, data);
	return (EXIT_SUCCESS);
}

int	handle_key_press(int keycode, t_cub3D_data *data)
{
	if (keycode == ESC_KEY_CODE)
	{
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
	mlx_destroy_window(data->window.mlx, data->window.address);
	mlx_destroy_display(data->window.mlx);
	free(data->window.mlx);
	destroy_map(data->map_data.map, 5);
	exit (0);
}