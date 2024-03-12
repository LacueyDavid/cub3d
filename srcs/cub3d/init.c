/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:57:28 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/11 15:52:13 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_window(t_window *window)
{
	window->mlx = mlx_init();
	if (!(window->mlx))
		return (EXIT_FAILURE);
	window->address = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!(window->address))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	init_img(t_window *window, t_img *img)
{
	(void)window;
	(void)img;
	return (0);
}
