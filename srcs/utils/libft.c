/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:32:54 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/09 11:35:43 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include "libft_and_utils.h"
#include "player.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

int	rgb_to_int(t_color_rgb color_rgb)
{
	return (color_rgb.r << 16 | color_rgb.g << 8 | color_rgb.b);
}

char	**ft_realloc(char **file, char *line)
{
	int		size;
	int		i;
	int		n;
	char	**new;

	size = 0;
	i = -1;
	while (file[size])
		size++;
	new = malloc(sizeof(char *) * (size + 2));
	while (file[++i])
	{
		n = -1;
		new[i] = malloc(sizeof(char) * ((ft_strlen(file[i]) + 1)));
		while (file[i][++n])
			new[i][n] = file[i][n];
		new[i][n] = '\0';
	}
	new[i] = ft_strdup(line);
	new[++i] = NULL;
	return (free_file(file), new);
}

void	free_file(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
		free(file[i]);
	free(file);
}
