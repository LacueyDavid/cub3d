/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:36:59 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 14:01:11 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct ray
{
	float	distance;
	float	distance_v;
	float	distance_h;
	float	smallest_distance;
	float	invert_tan;
	float	tan;
	float	angle;
	float	angle_precision;
	float	x;
	float	y;
	float	vx;
	float	vy;
	float	x_offset;
	float	y_offset;
	float	numbers;
	int		max;
	int		depth_of_field;
	int		line_height;
}			t_ray;

#endif
