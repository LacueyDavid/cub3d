/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/12 17:39:54 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_player(t_player *player)
{
	player->point.pos_x = 300;
	player->point.pos_y = 300;
	player->size = 4;
	player->color[0] = 255;
	player->color[1] = 255;
	player->color[2] = 0;
	return (true);
}

int	main(int argc, char **argv)
{
	t_cub3D_data	data;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	parsing_map(argv[1], &data.map_data);
	if (!create_session(&data.window, &data.img_data))
		return (error_mlx(), EXIT_FAILURE); // Don't forget to clear/free the data
	create_player(&data.player);
	cub3d(&data);
	terminate_session(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
