/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/29 07:50:32 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include "image_data.h"
# include "parser.h"
# include "player.h"

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	arrow_left;
	bool	arrow_right;
	bool	tab;
	bool	shift;
	bool	r;
	bool	h;
}				t_keys;

typedef struct s_cub3D_data
{
	t_map_data	map_data;
	t_window	window;
	t_img_data	img_data;
	t_player	player;
	t_keys		key;
}	t_cub3D_data;

// main programe

// close_window.c
bool	terminate_session(t_cub3D_data *data);
//// hooks to close the window and terminate the program
int		handle_window_close(t_cub3D_data *data);
int		handle_escape_press(int keycode, t_cub3D_data *data);

//// cub3d.c
int		cub3d(t_cub3D_data *data);

//// hook to moove the player
bool	key_board_hooks(t_cub3D_data *data);

#endif
