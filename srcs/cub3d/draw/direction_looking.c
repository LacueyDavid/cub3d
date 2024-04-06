/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_looking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:25:55 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 02:09:21 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "draw.h"

void	looking_left(t_cub3D_data *data, t_ray *ray)
{
	int	gap;

	gap = data->map_data.gap;
	ray->x = (((int)data->player.position.x / gap) * gap) + gap;
	ray->y = (data->player.position.x - ray->x) * ray->tan
		+ data->player.position.y;
	ray->x_offset = gap;
	ray->y_offset = -ray->x_offset * ray->tan;
}

void	looking_right(t_cub3D_data *data, t_ray *ray)
{
	int	gap;

	gap = data->map_data.gap;
	ray->x = (((int)data->player.position.x / gap) * gap) - 0.0001;
	ray->y = (data->player.position.x - ray->x) * ray->tan
		+ data->player.position.y;
	ray->x_offset = -gap;
	ray->y_offset = -ray->x_offset * ray->tan;
}

void	looking_up(t_cub3D_data *data, t_ray *ray)
{
	int	gap;

	gap = data->map_data.gap;
	ray->y = (((int)data->player.position.y / gap) * gap) - 0.0001;
	ray->x = (data->player.position.y - ray->y) * ray->invert_tan
		+ data->player.position.x;
	ray->y_offset = -gap;
	ray->x_offset = -ray->y_offset * ray->invert_tan;
}

void	looking_down(t_cub3D_data *data, t_ray *ray)
{
	int	gap;

	gap = data->map_data.gap;
	ray->y = (((int)data->player.position.y / gap) * gap) + gap;
	ray->x = (data->player.position.y - ray->y) * ray->invert_tan
		+ data->player.position.x;
	ray->y_offset = gap;
	ray->x_offset = -ray->y_offset * ray->invert_tan;
}

void	looking_straight_sides(t_cub3D_data *data, t_ray *ray, int *bigger)
{
	ray->x = data->player.position.x;
	ray->y = data->player.position.y;
	ray->depth_of_field = *bigger;
}
