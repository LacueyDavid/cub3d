/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:52 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/09 10:11:17 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "libft_and_utils.h"
#include "parser.h"

bool	get_ceiling_values(char *line, t_map_data *data)
{
	int	i;

	i = -1;
	data->ceiling_color.r = -1;
	data->ceiling_color.g = -1;
	data->ceiling_color.b = -1;
	if (line[i] && line[i] != '\n')
		data->ceiling_color.r = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		data->ceiling_color.g = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		data->ceiling_color.b = get_number(&line[i]);
	if (is_an_rgb_color(data->ceiling_color))
		return (true);
	return (false);
}

bool	get_floor_values(char *line, t_map_data *data)
{
	int	i;

	i = -1;
	data->floor_color.r = -1;
	data->floor_color.g = -1;
	data->floor_color.b = -1;
	if (line[i] && line[i] != '\n' && line[i + 1] != ',')
		data->floor_color.r = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		data->floor_color.g = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		data->floor_color.b = get_number(&line[i]);
	if (is_an_rgb_color(data->floor_color))
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
			if (!check_color(file[i] + n + 1))
				return (printf("error: invalid ceiling color values.\n"),
					false);
			n += 1;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			if (!get_ceiling_values(file[i] + n, data))
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
			if (!check_color(file[i] + n + 1))
				return (printf("error: invalid floor color values.\n"), false);
			n += 1;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			if (!get_floor_values(file[i] + n, data))
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
