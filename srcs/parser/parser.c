/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:00:00 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/14 15:33:50 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"
#include <string.h>

void	destroy_map(t_map_enum **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
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

void	free_file(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
}

char	**ft_realloc(char **file, char *line)
{
	int		size;
	int		i;
	int		n;
	char	**new;

	size = 0;
	i = -1;
	while (file[size])
		size++;
	new = malloc(sizeof(char *) * (size + 2));
	while (file[++i])
	{
		n = -1;
		new[i] = malloc(sizeof(char) * ((ft_strlen(file[i]) + 1)));
		while (file[i][++n])
			new[i][n] = file[i][n];
		new[i][n] = '\0';
	}
	new[i] = ft_strdup(line);
	new[++i] = NULL;
	return (free_file(file), new);
}

bool	parsing_map(char *filepath, t_map_data *map_data)
{
	int		fd;
	char	*line;
	char	**file;

	if (!check_filename_extention(filepath))
		return (error_wrong_extention(), false);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (error_map_not_found(), false);
	file = malloc(sizeof(char *));
	file[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = ft_realloc(file, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!get_textures(file, map_data) || !get_colors(file, map_data)
		|| !get_map(file, map_data))
		return (free_file(file), close(fd), false);
	return (free_file(file), close(fd), true);
}
