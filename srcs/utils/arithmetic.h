/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:56:23 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/20 12:05:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_H
# define ARITHMETIC_H

typedef struct s_point_int
{
	int		x;
	int		y;
}				t_point_int;

typedef struct s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct s_line
{
	t_point_int	p1;
	t_point_int	p2;
}				t_line;

#endif
