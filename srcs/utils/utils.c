/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:28:04 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 12:17:51 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_print(t_map_enum index)
{
	if (index == SPACE)
		printf(" ");
	else if (index == WALL)
		printf("1");
	else if (index == VOID)
		printf("0");
	else if (index == NORTH)
		printf("N");
	else if (index == SOUTH)
		printf("S");
	else if (index == EAST)
		printf("E");
	else if (index == WEST)
		printf("W");
}

void	print_map(t_map_enum **map, int height, int width)
{
	int	i;
	int	n;

	i = -1;
	while (++i < height)
	{
		n = -1;
		while (++n < width)
			select_print(map[i][n]);
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
