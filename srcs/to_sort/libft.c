/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:19:45 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/13 13:14:47 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int		rgb_to_int(int color_rgb[3])
{
	return (color_rgb[0] << 16 | color_rgb[1] << 8 | color_rgb[2]);
}

bool	reset_image(t_cub3D_data *data)
{
	ft_bzero(data->img_data.address,
		WIDTH * HEIGHT * data->img_data.bits_per_pixel / 8);
	return (true);
}
