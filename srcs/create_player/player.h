/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 15:47:16 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d_includes.h"
# include "parser.h"

typedef struct s_point
{
	float		x;
	float		y;
}			t_point;

typedef struct s_int_point
{
	int	x;
	int	y;
}			t_int_point;

typedef struct s_line
{
	t_int_point	p1;
	t_int_point	p2;
}				t_line;

typedef struct s_player
{
	int		orientation;
	t_point	position;
	float	delta_x;
	float	delta_y;
	float	angle;
	int		color[3];
	int		size;
}				t_player;

void	set_player_size(t_player *player, t_map_data *map_data);
void	set_player_color(t_player *player);
void	set_first_player_position(t_player *player, t_map_data *map_data);
void	set_player_orientation(t_player *player);
bool	create_player(t_player *player, t_map_data *map_data);

#endif
