/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 12:51:08 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "cub3d.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	t_cub3D_data	data;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	if (!parsing_map(argv[1], &data.map_data))
		return (EXIT_FAILURE);
	if (!create_session(&data.window, &data.img_data))
		return (error_mlx(), EXIT_FAILURE);
	create_player(&data.player, &data.map_data);
	cub3d(&data);
	//mouse_hook(&data); // Uncomment this line to enable mouse hook (laggy on mac and WSL)
	key_board_hooks(&data);
	terminate_session(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
