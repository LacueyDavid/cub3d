/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 14:20:43 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	parsing_map(argv[1], &data);
	if (!create_window(&data.window, &data.img_data))
		return (error_mlx(), EXIT_FAILURE); // Don't forget to clear/free the data
	mlx_destroy_image(data.window.mlx, data.img_data.img);
	close_window(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
