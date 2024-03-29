/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/29 15:10:49 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub3d.h"

typedef struct s_handle_walls
{
	int			x_offset;
	int			y_offset;
	int			ipx;
	int			ipy;
	int			ipx_add_xo;
	int			ipy_add_yo;
	int			ipx_sub_xo;
	int			ipy_sub_yo;
	int			ipx_add_xod;
	int			ipy_add_yod;
	int			ipx_sub_xod;
	int			ipy_sub_yod;
}				t_handle_walls;

void	do_key_press(t_cub3D_data *data, int keycode);
void	do_key_release(t_cub3D_data *data, int keycode);
void	reset_player(t_cub3D_data *data);
void	do_shift_key(t_cub3D_data *data);
void	init_handle_walls(t_handle_walls *handle_walls, t_cub3D_data *data);
void	do_arrow_left_key(t_cub3D_data *data);
void	do_arrow_right_key(t_cub3D_data *data);
void	do_movement_keys(t_cub3D_data *data);
void	init_keys(t_keys *keys);

#endif
