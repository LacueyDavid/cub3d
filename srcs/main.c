/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:55:09 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/13 05:21:36 by dlacuey          ###   ########.fr       */
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

int handle_moving_press(int keycode, t_cub3D_data *data)
{
	if (keycode == W_KEY_CODE)
	{
		data->player.point.pos_y -= 10;
		cub3d(data);
	}
	if (keycode == S_KEY_CODE)
	{
		data->player.point.pos_y += 10;
		cub3d(data);
	}
	if (keycode == A_KEY_CODE)
	{
		data->player.point.pos_x -= 10;
		cub3d(data);
	}
	if (keycode == D_KEY_CODE)
	{
		data->player.point.pos_x += 10;
		cub3d(data);
	}
	return (true);
}

bool	key_board_hooks(t_cub3D_data *data)
{
	mlx_hook(data->window.address, 2, 1L << 0, handle_moving_press, data);
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
	key_board_hooks(&data);
	terminate_session(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
