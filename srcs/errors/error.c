/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:00:22 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/18 13:42:17 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	error_wrong_extention(void)
{
	printf("error: wrong file extention, expected : [filename].cub\n");
}

void	error_map_not_found(void)
{
	printf("error: map file does not exist.\n");
}

void	error_parsing(void)
{
	printf("error: invalid map\n");
}

void	error_usage(void)
{
	printf("usage: ./cub [filepath]\n");
}

void	error_mlx(void)
{
	printf("error: mlx function failure\n");
}
