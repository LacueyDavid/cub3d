/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:13:37 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 13:26:23 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hooks.h"
#include "mlx.h"
#include "keycode.h"
#include <stdlib.h>

int	handle_escape_press(int keycode, t_cub3D_data *data)
{
	if (keycode == ESC_KEY_CODE)
	{
		mlx_destroy_image(data->window.mlx, data->img_data.img);
		mlx_destroy_window(data->window.mlx, data->window.address);
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
		free(data->map_data.north_img);
		free(data->map_data.south_img);
		free(data->map_data.east_img);
		free(data->map_data.west_img);
		destroy_map(data->map_data.map, data->map_data.height);
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
	free(data->map_data.north_img);
	free(data->map_data.south_img);
	free(data->map_data.east_img);
	free(data->map_data.west_img);
	destroy_map(data->map_data.map, data->map_data.height);
	exit (0);
}

int	handle_moving_press(int keycode, t_cub3D_data *data)
{
	do_key_press(data, keycode);
	return (true);
}

int	handle_moving_release(int keycode, t_cub3D_data *data)
{
	handle_escape_press(keycode, data);
	do_key_release(data, keycode);
	return (true);
}

bool	key_board_hooks(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 2, 1L << 0, handle_moving_press, data);
	mlx_hook(data->window.address, 3, 1L << 1, handle_moving_release, data);
	mlx_hook(data->window.address, 17, 0, handle_window_close, data);
	return (true);
}
