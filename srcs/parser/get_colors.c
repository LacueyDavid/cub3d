/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:52 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/18 13:55:40 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "libft_and_utils.h"
#include "parser.h"

bool	get_values(char *line, t_color_rgb tab)
{
	int	i;

	i = -1;
	tab.r = -1;
	tab.g = -1;
	tab.b = -1;
	if (line[i] && line[i] != '\n')
		tab.r = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		tab.g = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		tab.b = get_number(&line[i]);
	if (tab.r >= 0 && tab.r <= 255 && tab.g >= 0
		&& tab.g <= 255 && tab.b >= 0 && tab.b <= 255)
		return (true);
	return (false);
}

bool	get_ceiling(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'C' && file[i][n + 1] == ' ')
		{
			n += 1;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			if (!get_values(file[i] + n, data->ceiling_color))
				return (printf("error: invalid ceiling color value.\n"), false);
			return (true);
		}
	}
	return (printf("error: missing ceiling colors in .cub file\n"), false);
}

bool	get_floor(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'F' && file[i][n + 1] == ' ')
		{
			n += 1;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			if (!get_values(file[i] + n, data->floor_color))
				return (printf("error: invalid floor color values.\n"), false);
			return (true);
		}
	}
	return (printf("error: missing floor colors in .cub file\n"), false);
}

bool	get_colors(char **file, t_map_data *data)
{
	if (!get_ceiling(file, data))
		return (false);
	if (!get_floor(file, data))
		return (false);
	return (true);
}
