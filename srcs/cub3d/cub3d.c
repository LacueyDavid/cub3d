/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 16:26:54 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d(int argc, char **argv)
{
	t_data		data;
	t_img		img;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	parsing_map(argv[1], &data);
	if (create_window(&data.window) == EXIT_FAILURE)
		return (error_mlx(), EXIT_FAILURE); // Don't forget to clear/free the data
	init_img(&data.window, &img);
	close_window(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
