/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 13:14:20 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_window	window;
	t_map		map;
	t_img		img;

	if (ac != 2)
		return (error_usage(), EXIT_FAILURE);
	parsing_map(av[1], &map);
	if (create_window(&window) == EXIT_FAILURE)
		return (error_mlx(), EXIT_FAILURE); // Don't forget to clear/free the map
	init_img(&window, &img);
	close_window(&window);
	mlx_loop(window.mlx);
	return (EXIT_SUCCESS);
}
