/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:08:44 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 13:29:57 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_and_utils.h"

void	set_color(t_color_rgb *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

bool	is_an_rgb_color(t_color_rgb color)
{
	if (color.r >= 0 && color.r <= 255
		&& color.g >= 0 && color.g <= 255
		&& color.b >= 0 && color.b <= 255)
		return (true);
	return (false);
}

bool	check_color(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (!is_whitespace(line[i])
			&& (line[i] > '9' || line[i] < '0') && line[i] != ',')
			return (false);
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (false);
	return (true);
}
