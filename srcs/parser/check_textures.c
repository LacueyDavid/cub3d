/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:18:28 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/09 11:44:59 by jugingas         ###   ########.fr       */
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

bool	is_xpm(char *line, char *name)
{
	if (ft_strncmp(line, "/* XPM */", 9))
		return (printf("error: %s texture is not a xpm file\n", name),
			false);
	return (true);
}

bool	check_res(char *name, int fd)
{
	char	*line;
	int		resolution;

	line = get_next_line(fd);
	resolution = 0;
	if (!is_xpm(line, name))
	{
		free(line);
		return (false);
	}
	while (line)
	{
		if (!ft_strncmp(line, "\"",1) && !resolution)
			resolution = get_number(line + 1);
		free(line);
		line = get_next_line(fd);
	}
	if (resolution < 1)
		return (printf("error: %s texture resolution is too small\n", name),
			close(fd), false);
	if (resolution > 512)
		return (printf("error: %s texture resolution is too big\n", name),
			close(fd), false);
	return (close(fd), true);
}

bool	check_textures(t_map_data *data)
{
	int	fd_north;
	int	fd_south;
	int	fd_west;
	int	fd_east;

	fd_north = open(data->north_img, O_RDONLY);
	fd_south = open(data->south_img, O_RDONLY);
	fd_west = open(data->west_img, O_RDONLY);
	fd_east = open(data->east_img, O_RDONLY);
	if (fd_north == -1 || fd_south == -1 || fd_west == -1 || fd_east == -1)
		return (printf("error: could not open textures\n"), false);
	if (!check_res("north", fd_north)
		|| !check_res("south", fd_south)
		|| !check_res("west", fd_west)
		|| !check_res("east", fd_east))
		return (false);
	close(fd_north);
	close(fd_south);
	close(fd_west);
	close(fd_east);
	return (true);
}
