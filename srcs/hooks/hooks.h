/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:31:52 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "cub3d.h"
# include "parser.h"

# define BASE 0.0005
# define MAX 1500.0
# define SCALE 0.00005

typedef struct s_cub3d_data	t_cub3d_data;

typedef struct s_keys		t_keys;

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

typedef struct s_mouse
{
	int		prev_x;
	int		prev_y;
	double	delta_x;
	bool	mouse_reset;
	double	rotation_speed;
	double	accumulated_delta_x;
}				t_mouse;

void	ensure_player_is_in_map(t_cub3d_data *data);
void	do_key_press(t_cub3d_data *data, int keycode);
void	do_key_release(t_cub3d_data *data, int keycode);
void	destroy_img(t_map_data *data);
void	reset_player(t_cub3d_data *data);
void	do_shift_key(t_cub3d_data *data);
void	do_alt_key(t_cub3d_data *data);
void	init_handle_walls(t_handle_walls *handle_walls, t_cub3d_data *data);
void	do_arrow_left_key(t_cub3d_data *data);
void	do_arrow_right_key(t_cub3d_data *data);
void	do_movement_keys(t_cub3d_data *data);
void	init_keys(t_keys *keys);
void	init_mouse(t_cub3d_data *data);
bool	mouse_hook(t_cub3d_data *data);

#endif
