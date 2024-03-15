/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:19:45 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/15 12:39:12 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
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

int	rgb_to_int(int color_rgb[3])
{
	return (color_rgb[0] << 16 | color_rgb[1] << 8 | color_rgb[2]);
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
