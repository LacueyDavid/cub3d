/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/11 15:50:47 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3D_data	data;

	// protect input
	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	// parse input
	parsing_map(argv[1], &data.map_data);
	// protect window
	if (create_window(&data.window) == EXIT_FAILURE)
		return (error_mlx(), EXIT_FAILURE); // Don't forget to clear/free the data
	cub3D(&data);
	terminate_session(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
