/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:57:28 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 12:57:51 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	create_window(t_window *window)
{
	window->mlx = mlx_init();
	if (!(window->mlx))
		return (EXIT_FAILURE);
	window->window = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!(window->window))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	init_img(t_window *window, t_img *img)
{
	(void)window;
	(void)img;
	return (0);
}
