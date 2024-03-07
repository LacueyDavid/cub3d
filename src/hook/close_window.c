/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:04:13 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 13:10:18 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	close_window(t_window *window)
{
	mlx_hook(window->window, 17, 0, handle_window_close, window);
	mlx_key_hook(window->window, handle_key_press, window);
	return (EXIT_SUCCESS);
}

int	handle_key_press(int keycode, t_window *window)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(window->mlx, window->window);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		exit (0);
	}
	return (0);
}

int	handle_window_close(t_window *window)
{
	mlx_destroy_window(window->mlx, window->window);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit (0);
}
