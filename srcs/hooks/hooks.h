/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/28 04:06:40 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

#include "cub3d.h"

void	do_key_press(t_cub3D_data *data, int keycode);
void	do_key_release(t_cub3D_data *data, int keycode);

#endif
