/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:02:48 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/14 14:00:44 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_around(char **map, int i, int n)
{
	if (i == 0 || !map[i - 1][n] || is_whitespace(map[i - 1][n]))
		return (false);
	if (!map[i + 1] || is_whitespace(map[i + 1][n]))
		return (false);
	if (n == 0 || !map[i][n - 1] || is_whitespace(map[i][n - 1]))
		return (false);
	if (!map[i][n + 1] || is_whitespace(map[i][n + 1]))
		return (false);
	return (true);
}

bool	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	is_valid_map_char(char c)
{
	if (c == '1' || c == '0' || is_whitespace(c)
		|| is_player_char(c))
		return (true);
	return (false);
}

bool	check_map(char **map)
{
	int	i;
	int	n;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		n = -1;
		while (map[i][++n] && map[i][n] != '\n')
		{
			if (map[i][n] == '0')
				if (!check_around(map, i, n))
					return (printf("error: map is open.\n"), false);
			if (is_player_char(map[i][n]))
				count++;
			if (!is_valid_map_char(map[i][n]))
				return (printf("error: invalid character found.\n"), false);
		}
	}
	if (count == 0)
		return (printf("error: missing player position.\n"), false);
	if (count > 1)
		return (printf("error: multiple player positions.\n"), false);
	return (true);
}
