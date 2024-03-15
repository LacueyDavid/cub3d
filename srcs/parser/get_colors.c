/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:26:52 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 15:14:53 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_values(char *line, int *tab)
{
	int	i;

	i = -1;
	tab[0] = -1;
	tab[1] = -1;
	tab[2] = -1;
	if (line[i] && line[i] != '\n')
		tab[0] = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		tab[1] = get_number(&line[i]);
	while (line[i] && line[i] != ',' && (is_whitespace(line[i])
			|| (line[i] >= '0' && line[i] <= '9')))
		i++;
	i++;
	if (line[i] && line[i] != '\n')
		tab[2] = get_number(&line[i]);
	if (tab[0] >= 0 && tab[0] <= 255 && tab[1] >= 0
		&& tab[1] <= 255 && tab[2] >= 0 && tab[2] <= 255)
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
				return (printf("error: invalid ceiling color values.\n"), false);
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
