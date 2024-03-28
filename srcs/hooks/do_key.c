/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:20:32 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 06:39:15 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keycode.h"

void	do_key_press(t_cub3D_data *data, int keycode)
{
	if (keycode == W_KEY_CODE)
		data->key.w = true;
	if (keycode == S_KEY_CODE)
		data->key.s = true;
	if (keycode == A_KEY_CODE)
		data->key.a = true;
	if (keycode == D_KEY_CODE)
		data->key.d = true;
	if (keycode == ARROW_LEFT_CODE)
		data->key.arrow_left = true;
	if (keycode == ARROW_RIGHT_CODE)
		data->key.arrow_right = true;
	if (keycode == TAB_CODE)
		data->key.tab = !data->key.tab;
	if (keycode == SHIFT_CODE)
		data->key.shift = true;
}

void	do_key_release(t_cub3D_data *data, int keycode)
{
	if (keycode == W_KEY_CODE)
		data->key.w = false;
	if (keycode == S_KEY_CODE)
		data->key.s = false;
	if (keycode == A_KEY_CODE)
		data->key.a = false;
	if (keycode == D_KEY_CODE)
		data->key.d = false;
	if (keycode == ARROW_LEFT_CODE)
		data->key.arrow_left = false;
	if (keycode == ARROW_RIGHT_CODE)
		data->key.arrow_right = false;
	if (keycode == SHIFT_CODE)
		data->key.shift = false;
}
