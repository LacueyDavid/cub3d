/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:04 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/14 11:28:41 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map_enum **map, int height, int width)
{
	int	i;
	int	n;

	i = -1;
	while (++i < height)
	{
		n = -1;
		while (++n < width)
		{
			if (map[i][n] == SPACE)
				printf(" ");
			else if (map[i][n] == WALL)
				printf("1");
			else if (map[i][n] == VOID)
				printf("0");
			else if (map[i][n] == NORTH)
				printf("N");
			else if (map[i][n] == SOUTH)
				printf("S");
			else if (map[i][n] == EAST)
				printf("E");
			else if (map[i][n] == WEST)
				printf("W");
		}
		printf("\n");
	}
}

bool	is_whitespace(char c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return (true);
	return (false);
}

int	get_number(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!is_whitespace(str[0]) && (str[0] < '0' || str[0] > '9'))
		return (-1);
	while (is_whitespace(str[i]))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * ((ft_strlen(str) + 1)));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
