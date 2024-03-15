/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:54:23 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 13:08:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d_includes.h"

typedef enum e_map_enum
{
	SPACE,
	WALL,
	VOID,
	NORTH,
	SOUTH,
	WEST,
	EAST,
}			t_map_enum;

typedef struct s_map_data
{
	t_map_enum	**map;
	int			width;
	int			height;
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	int			floor_color[3];
	int			ceiling_color[3];
	int			minimap_wall_color[3];
	int			gap;
}				t_map_data;

void		print_map(t_map_enum **map, int height, int width);
bool		parsing_map(char *filepath, t_map_data *map);
int			get_map_size(char **map);
t_map_enum	*fill_with_spaces(t_map_enum *map, int i, int width);
bool		get_textures(char **file, t_map_data *data);
bool		get_colors(char **file, t_map_data *data);
bool		get_map(char **file, t_map_data *data);
void		destroy_map(t_map_enum **map, int height);
bool		check_map(char **map);
bool		is_map_line(char *line);
int			skip_texture_and_colors(char **file);

#endif
