/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:27:01 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/08 13:18:26 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <libft_and_utils.h>
#include "parser.h"

bool	get_north(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'N' && file[i][n + 1] == 'O' && file[i][n + 2] == ' ')
		{
			n += 2;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			data->north_img = ft_strdup(file[i] + n);
			if (!data->north_img)
				return (printf("error: memory allocation failed.\n"), false);
			data->north_img[ft_strlen(data->north_img) - 1] = '\0';
			return (true);
		}
	}
	return (false);
}

bool	get_south(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'S' && file[i][n + 1] == 'O' && file[i][n + 2] == ' ')
		{
			n += 2;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			data->south_img = ft_strdup(file[i] + n);
			if (!data->south_img)
				return (printf("error: memory allocation failed.\n"), false);
			data->south_img[ft_strlen(data->south_img) - 1] = '\0';
			return (true);
		}
	}
	return (false);
}

bool	get_east(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'E' && file[i][n + 1] == 'A' && file[i][n + 2] == ' ')
		{
			n += 2;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			data->east_img = ft_strdup(file[i] + n);
			if (!data->east_img)
				return (printf("error: memory allocation failed.\n"), false);
			data->east_img[ft_strlen(data->east_img) - 1] = '\0';
			return (true);
		}
	}
	return (false);
}

bool	get_west(char **file, t_map_data *data)
{
	int	i;
	int	n;

	i = -1;
	while (file[++i])
	{
		n = 0;
		while (file[i][n] && is_whitespace(file[i][n]))
			n++;
		if (file[i][n] == 'W' && file[i][n + 1] == 'E' && file[i][n + 2] == ' ')
		{
			n += 2;
			while (file[i][n] && is_whitespace(file[i][n]))
				n++;
			data->west_img = ft_strdup(file[i] + n);
			if (!data->west_img)
				return (printf("error: memory allocation failed.\n"), false);
			data->west_img[ft_strlen(data->west_img) - 1] = '\0';
			return (true);
		}
	}
	return (false);
}

bool	get_textures(char **file, t_map_data *data)
{
	int	fd;

	if (!get_north(file, data) || !get_south(file, data)
		|| !get_east(file, data) || !get_west(file, data))
		return (printf("error: missing texture path in .cub file\n"), false);
	fd = open(data->north_img, O_RDONLY);
	if (fd == -1)
		return (printf("error: north wall texture does not exist.\n"), false);
	close(fd);
	fd = open(data->south_img, O_RDONLY);
	if (fd == -1)
		return (printf("error: south wall texture does not exist.\n"), false);
	close(fd);
	fd = open(data->east_img, O_RDONLY);
	if (fd == -1)
		return (printf("error: east wall texture does not exist.\n"), false);
	close(fd);
	fd = open(data->west_img, O_RDONLY);
	if (fd == -1)
		return (printf("error: west wall texture does not exist.\n"), false);
	close(fd);
	if (!check_textures(data))
		return (false);
	return (true);
}
