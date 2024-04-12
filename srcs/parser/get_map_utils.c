/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:57:47 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/10 14:13:53 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

bool	check_xpm_extention(char *line)
{
	if (line[ft_strlen(line) - 2] == 'm' && line[ft_strlen(line) - 3] == 'p'
		&& line[ft_strlen(line) - 4] == 'x' && line[ft_strlen(line) - 5] == '.')
		return (true);
	return (false);
}

int	skip_texture_and_colors(char **file)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (file[++i])
	{
		if (file[i][0] == 'N' && file[i][1] == 'O' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'S' && file[i][1] == 'O' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'W' && file[i][1] == 'E' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'E' && file[i][1] == 'A' && file[i][2] == ' ')
			count++;
		else if (file[i][0] == 'F' && file[i][1] == ' ')
			count++;
		else if (file[i][0] == 'C' && file[i][1] == ' ')
			count++;
		if (count == 6)
			return (i + 1);
	}
	return (false);
}

bool	is_map_line(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (false);
	while (line[++i])
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (true);
	return (false);
}

int	get_map_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] && is_map_line(map[i]))
		i++;
	return (i);
}

t_map_enum	*fill_with_spaces(t_map_enum *map, int i, int width)
{
	while (i < width)
	{
		map[i] = SPACE;
		i++;
	}
	return (map);
}
