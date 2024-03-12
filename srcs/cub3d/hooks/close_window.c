/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:04:13 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 14:20:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	close_window(t_data *data)
{
	mlx_hook(data->window.window, 17, 0, handle_window_close, data);
	mlx_key_hook(data->window.window, handle_key_press, data);
	return (EXIT_SUCCESS);
}

int	handle_key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->window.mlx, data->window.window);
		mlx_destroy_display(data->window.mlx);
		free(data->window.mlx);
		destroy_map(data->map, 5);
		exit (0);
	}
	return (0);
}

int	handle_window_close(t_data *data)
{
	mlx_destroy_window(data->window.mlx, data->window.window);
	mlx_destroy_display(data->window.mlx);
	free(data->window.mlx);
	destroy_map(data->map, 5);
	exit (0);
}
