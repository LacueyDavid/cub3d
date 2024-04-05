/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:06 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/05 08:08:12 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_and_utils.h"

int	which_is_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	which_is_lower(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	set_color(t_color_rgb *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

int	color_red(void)
{
	return (255 << 16);
}
