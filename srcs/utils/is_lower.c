/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:34:06 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/08 18:11:57 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_and_utils.h"

int	which_is_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	which_is_lower(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
