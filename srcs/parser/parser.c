/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:00:00 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/07 15:56:49 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft_and_utils.h"
#include "errors.h"
#include "get_next_line.h"
#include "cub3d_useful_values.h"
#include "parser.h"
#include "minimap.h"

void	free_textures(t_map_data *map_data)
{
	free(map_data->north_img);
	free(map_data->south_img);
	free(map_data->east_img);
	free(map_data->west_img);
}

bool	check_filename_extention(char *filepath)
{
	int	i;

	i = ft_strlen(filepath);
	while (i > 0 && filepath[i] != '.')
		i--;
	if (filepath[i] == '.' && filepath[i + 1] == 'c'
		&& filepath[i + 2] == 'u' && filepath[i + 3] == 'b'
		&& filepath[i + 4] == '\0')
		return (true);
	return (false);
}

bool	fill_file(char ***file, char *filepath)
{
	int		fd;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (error_map_not_found(), false);
	*file = malloc(sizeof(char *));
	if (!*file)
		return (close(fd), error_malloc(), false);
	(*file)[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		*file = ft_realloc(*file, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}

void	set_gap(t_map_data *map_data)
{
	int	lower;

	map_data->screen_smallest_side = which_is_lower(WIDTH, HEIGHT);
	lower = map_data->screen_smallest_side;
	if (map_data->width > map_data->height)
		map_data->gap = (lower / 4) / map_data->width;
	else
		map_data->gap = (lower / 4) / map_data->height;
	if (map_data->gap < 5)
		map_data->gap = 5;
}

bool	parsing_map(char *filepath, t_map_data *map_data)
{
	char	**file;

	if (!check_filename_extention(filepath))
		return (error_wrong_extention(), false);
	if (!fill_file(&file, filepath))
		return (false);
	if (!get_textures(file, map_data))
		return (free_file(file), false);
	else if (!get_colors(file, map_data))
		return (free_file(file), free_textures(map_data), false);
	else if (!get_map(file, map_data))
		return (free_file(file), free_textures(map_data), false);
	(free_file(file));
	set_minimap_colors(map_data);
	set_gap(map_data);
	map_data->biggest_side = which_is_bigger(map_data->width, map_data->height);
	map_data->smallest_side = which_is_lower(map_data->width, map_data->height);
	return (true);
}
