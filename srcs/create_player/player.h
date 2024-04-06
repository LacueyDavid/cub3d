/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/06 13:23:20 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "libft_and_utils.h"
# include "parser.h"
# include "arithmetic.h"

typedef struct s_player
{
	t_point		first_position;
	float		first_angle;
	float		orientation;
	t_point		position;
	float		delta_x;
	float		delta_y;
	float		angle;
	t_color_rgb	color;
	float		size;
	float		speed;
	float		rotate_speed;
}				t_player;

void	set_player_size(t_player *player, t_map_data *map_data);
void	set_player_color(t_player *player);
void	set_first_player_position(t_player *player, t_map_data *map_data);
void	set_player_orientation(t_player *player);
bool	create_player(t_player *player, t_map_data *map_data);

#endif
