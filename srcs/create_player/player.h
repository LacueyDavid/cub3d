/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/19 11:12:42 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "libft_and_utils.h"
# include "parser.h"

typedef struct s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
}				t_line;

typedef struct s_player
{
	int			orientation;
	t_point		position;
	float		delta_x;
	float		delta_y;
	float		angle;
	t_color_rgb	color;
	int			size;
}				t_player;

void	set_player_size(t_player *player, t_map_data *map_data);
void	set_player_color(t_player *player);
void	set_first_player_position(t_player *player, t_map_data *map_data);
void	set_player_orientation(t_player *player);
bool	create_player(t_player *player, t_map_data *map_data);

#endif
