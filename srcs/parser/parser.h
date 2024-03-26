/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:54:23 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/26 06:15:24 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include "libft_and_utils.h"
# include <aio.h>

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
	t_color_rgb	floor_color;
	t_color_rgb	ceiling_color;
	t_color_rgb	minimap_wall_color;
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
