/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:00:00 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 12:45:00 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <string.h>

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

bool	parsing_map(char *filepath, t_map_data *map_data)
{
	char	**file;
	int		return_value;

	if (!check_filename_extention(filepath))
		return (error_wrong_extention(), false);
	if (!fill_file(&file, filepath))
		return (false);
	if (!get_textures(file, map_data))
		return_value = false;
	else if (!get_colors(file, map_data))
		return_value = false;
	else if (!get_map(file, map_data))
		return_value = false;
	else
		return_value = true;
	(free_file(file));
	set_minimap_colors(map_data);
	print_map(map_data->map, map_data->height, map_data->width);
	return (return_value);
}
