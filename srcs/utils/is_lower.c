/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:06 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/08 20:10:21 by jugingas         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}
