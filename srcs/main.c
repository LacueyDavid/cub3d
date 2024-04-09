/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:11:29 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "cub3d.h"
#include "errors.h"
#include "hooks.h"
#include <stdio.h>
#include "parser.h"
#include <stdio.h>

bool	init_image(t_map_data *map_data, int index)
{
	map_data->img[index].mlx = mlx_init();
	if (!map_data->img[index].mlx)
		return (printf("error: mlx init failed.\n"), false);
	map_data->img[index].img = mlx_xpm_file_to_image(map_data->img[index].mlx,
			map_data->img[index].path, &map_data->img[index].width,
			&map_data->img[index].height);
	map_data->img[index].data.address = mlx_get_data_addr(
			map_data->img[index].img,
			&map_data->img[index].data.bits_per_pixel,
			&map_data->img[index].data.line_length,
			&map_data->img[index].data.endian);
	map_data->img[index].data.img = map_data->img[index].img;
	if (!map_data->img[index].img)
		return (printf("error: mlx xpm conversion failed.\n"), false);
	return (true);
}

bool	take_img_path(t_map_data *map_data)
{
	map_data->img[NORTH].path = map_data->north_img;
	map_data->img[SOUTH].path = map_data->south_img;
	map_data->img[WEST].path = map_data->west_img;
	map_data->img[EAST].path = map_data->east_img;
	if (!init_image(map_data, NORTH) || !init_image(map_data, SOUTH)
		|| !init_image(map_data, WEST) || !init_image(map_data, EAST))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_cub3d_data	data;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	if (!create_session(&data.window, &data.img_data))
		return (error_mlx(), EXIT_FAILURE);
	if (!parsing_map(argv[1], &data.map_data))
		return (EXIT_FAILURE);
	if (!take_img_path(&data.map_data))
		return (EXIT_FAILURE);
	create_player(&data.player, &data.map_data);
	init_mouse(&data);
	init_keys(&data.key);
	cub3d(&data);
	key_board_hooks(&data);
	mlx_loop_hook(data.window.mlx, cub3d, &data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
