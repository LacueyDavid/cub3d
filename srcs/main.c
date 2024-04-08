/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/08 12:07:47 by dlacuey          ###   ########.fr       */
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
void	take_img_path(t_map_data *map_data)
{
	map_data->img[NORTH].path = map_data->north_img;
	map_data->img[SOUTH].path = map_data->south_img;
	map_data->img[WEST].path = map_data->west_img;
	map_data->img[EAST].path = map_data->east_img;
	map_data->img[NORTH].mlx = mlx_init();
	map_data->img[SOUTH].mlx = mlx_init();
	map_data->img[WEST].mlx = mlx_init();
	map_data->img[EAST].mlx = mlx_init();
	map_data->img[NORTH].img = mlx_xpm_file_to_image(map_data->img[NORTH].mlx,
			map_data->img[NORTH].path, &map_data->img[NORTH].width,
			&map_data->img[NORTH].height);
	map_data->img[SOUTH].img = mlx_xpm_file_to_image(map_data->img[SOUTH].mlx,
			map_data->img[SOUTH].path, &map_data->img[SOUTH].width,
			&map_data->img[SOUTH].height);
	map_data->img[WEST].img = mlx_xpm_file_to_image(map_data->img[WEST].mlx,
			map_data->img[WEST].path, &map_data->img[WEST].width,
			&map_data->img[WEST].height);
	map_data->img[EAST].img = mlx_xpm_file_to_image(map_data->img[EAST].mlx,
			map_data->img[EAST].path, &map_data->img[EAST].width,
			&map_data->img[EAST].height);
	if (!map_data->img[NORTH].img || !map_data->img[SOUTH].img
		|| !map_data->img[WEST].img || !map_data->img[EAST].img)
	{
		//PROTEGER ICI;
	}
	map_data->img[NORTH].data.address = mlx_get_data_addr(map_data->img[NORTH].img,
			&map_data->img[NORTH].data.bits_per_pixel,
			&map_data->img[NORTH].data.line_length,
			&map_data->img[NORTH].data.endian);
	map_data->img[SOUTH].data.address = mlx_get_data_addr(map_data->img[SOUTH].img,
			&map_data->img[SOUTH].data.bits_per_pixel,
			&map_data->img[SOUTH].data.line_length,
			&map_data->img[SOUTH].data.endian);
	map_data->img[WEST].data.address = mlx_get_data_addr(map_data->img[WEST].img,
			&map_data->img[WEST].data.bits_per_pixel,
			&map_data->img[WEST].data.line_length,
			&map_data->img[WEST].data.endian);
	map_data->img[EAST].data.address = mlx_get_data_addr(map_data->img[EAST].img,
			&map_data->img[EAST].data.bits_per_pixel,
			&map_data->img[EAST].data.line_length,
			&map_data->img[EAST].data.endian);
	map_data->img[NORTH].data.img = map_data->img[NORTH].img;
	map_data->img[SOUTH].data.img = map_data->img[SOUTH].img;
	map_data->img[WEST].data.img = map_data->img[WEST].img;
	map_data->img[EAST].data.img = map_data->img[EAST].img;
}

int	main(int argc, char **argv)
{
	t_cub3D_data	data;

	if (argc != 2)
		return (error_usage(), EXIT_FAILURE);
	if (!parsing_map(argv[1], &data.map_data))
		return (EXIT_FAILURE);
	if (!create_session(&data.window, &data.img_data))
		return (error_mlx(), EXIT_FAILURE);
	take_img_path(&data.map_data);
	create_player(&data.player, &data.map_data);
	init_keys(&data.key);
	mlx_mouse_hide(data.window.mlx, data.window.address);
	cub3d(&data);
	key_board_hooks(&data);
	mlx_loop_hook(data.window.mlx, cub3d, &data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
