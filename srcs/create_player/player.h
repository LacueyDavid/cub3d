/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 11:44:36 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d_includes.h"

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_player
{
	int		orientation;
	t_point	position;
	int		color[3];
	int		size;
}				t_player;

bool	create_player(t_player *player, t_map_data *map_data);
void	set_player_position(t_player *player, t_map_data *map_data);
void	set_player_size(t_player *player, t_map_data *map_data);
void	set_player_color(t_player *player);
#endif
