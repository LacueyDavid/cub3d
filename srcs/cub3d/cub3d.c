/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:43:57 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/29 14:53:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_data.h"
#include "draw.h"
#include "cub3d.h"
#include "cub3d_useful_values.h"
#include "mlx.h"
#include "libft_and_utils.h"
#include "hooks.h"

bool	reset_image(t_img_data *img_data)
{
	ft_bzero(img_data->address,
		WIDTH * HEIGHT * img_data->bits_per_pixel / 8);
	return (true);
}

static void	ensure_player_is_in_map(t_cub3D_data *data)
{
	int	one_block;

	one_block = data->map_data.gap;
	if (data->player.position.x < 0)
		data->player.position.x = 0;
	if (data->player.position.x > one_block * data->map_data.width)
		data->player.position.x = one_block * data->map_data.width;
	if (data->player.position.y < 0)
		data->player.position.y = 0;
	if (data->player.position.y > one_block * data->map_data.height)
		data->player.position.y = one_block * data->map_data.height;
}

// may add fps for bonus but need time function
void	key_gestion(t_cub3D_data *data)
{
	reset_player(data);
	do_shift_key(data);
	do_movement_keys(data);
	ensure_player_is_in_map(data);
}

// la fonction reset_image va surement disparaitre plus tard
int	cub3d(t_cub3D_data *data)
{
	key_gestion(data);
	reset_image(&data->img_data);
	draw_rays(data);
	if (data->key.tab)
	{
		draw_minimap(data);
		draw_player(data->player, data->img_data);
	}
	mlx_put_image_to_window(data->window.mlx,
		data->window.address, data->img_data.img, 0, 0);
	mlx_do_sync(data->window.mlx);
	return (1);
}
