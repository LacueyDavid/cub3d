/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:00:22 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 13:13:28 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_usage(void)
{
	printf("usage: ./cub [filepath]\n");
}

void	error_mlx(void)
{
	printf("error: mlx function failure\n");
}
