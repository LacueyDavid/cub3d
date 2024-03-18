/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:40 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/18 13:56:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "parser.h"

t_map_enum	*copy_line(t_map_enum *map, char *line, int width)
{
	int	i;

	i = -1;
	map = malloc(sizeof(t_map_enum) * width);
	if (!map)
		return (printf("error: memory allocation failed.\n"), NULL);
	while (line[++i] != '\n' && line[i])
	{
		if (line[i] == ' ')
			map[i] = SPACE;
		if (line[i] == '1')
			map[i] = WALL;
		if (line[i] == '0')
			map[i] = VOID;
		if (line[i] == 'N')
			map[i] = NORTH;
		if (line[i] == 'S')
			map[i] = SOUTH;
		if (line[i] == 'E')
			map[i] = EAST;
		if (line[i] == 'W')
			map[i] = WEST;
	}
	return (fill_with_spaces(map, i, width));
}

bool	copy_map(char **map, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (map[++i])
		if (is_map_line(map[i]))
			break ;
	if (!map[i])
		return (printf("error: no map in .cub file\n"), false);
	data->height = get_map_size(&map[i]);
	data->width = -1;
	data->map = malloc(sizeof(t_map_enum *) * data->height);
	if (!data->map)
		return (printf("error: memory allocation failed.\n"), false);
	while (map[i] && is_map_line(map[i]))
	{
		if (ft_strlen(map[i]) > data->width)
			data->width = ft_strlen(map[i]) - 1;
		data->map[n] = copy_line(data->map[n], map[i], data->width);
		n++;
		i++;
	}
	return (true);
}

bool	get_map(char **file, t_map_data *data)
{
	int	skip;

	skip = skip_texture_and_colors(file);
	if (!check_map(&file[skip]))
		return (false);
	if (!copy_map(&file[skip], data))
		return (false);
	return (true);
}
