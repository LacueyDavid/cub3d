/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:32:06 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/06 13:32:12 by jugingas         ###   ########.fr       */
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
