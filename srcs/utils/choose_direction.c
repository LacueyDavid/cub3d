/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:32:10 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 13:38:24 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include "ray.h"

bool	is_a_north_wall(t_ray *ray)
{
	return (ray->smallest_distance == ray->distance_h
		&& ray->angle > M_PI);
}

bool	is_a_west_wall(t_ray *ray)
{
	return (ray->smallest_distance == ray->distance_v
		&& (ray->angle < M_PI / 2 || ray->angle > 3 * M_PI / 2));
}

bool	is_a_east_wall(t_ray *ray)
{
	return (ray->smallest_distance == ray->distance_v
		&& (ray->angle > M_PI / 2 || ray->angle < 3 * M_PI / 2));
}

bool	is_a_south_wall(t_ray *ray)
{
	return (ray->smallest_distance == ray->distance_h
		&& ray->angle < M_PI);
}
