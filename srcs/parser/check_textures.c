/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:18:28 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/08 13:55:20 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include "libft_and_utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

bool	is_xpm(char *path, char *name)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (ft_strncmp(line, "/* XPM */", 9))
		return (printf("error: %s texture is not a xpm file\n", name),
			free(line), false);
	return (free(line), true);
}

bool	check_res(char *path, char *name)
{
	int		fd;
	char	*line;
	int		resolution;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (ft_strncmp(line, "\"", 1))
		line = get_next_line(fd);
	resolution = get_number(line + 1);
	if (resolution < 1)
		return (printf("error: %s texture resolution is too small\n", name),
			free(line), close(fd), false);
	if (resolution > 512)
		return (printf("error: %s texture resolution is too big\n", name),
			free(line), false);
	return (free(line), true);
}

bool	check_textures(t_map_data *data)
{
	if (!is_xpm(data->north_img, "north") || !is_xpm(data->south_img, "south")
		|| !is_xpm(data->west_img, "west") || !is_xpm(data->east_img, "east"))
		return (false);
	if (!check_res(data->north_img, "north")
		|| !check_res(data->south_img, "south")
		|| !check_res(data->west_img, "west")
		|| !check_res(data->east_img, "east"))
		return (false);
	return (true);
}
