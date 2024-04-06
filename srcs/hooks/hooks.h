/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:24:26 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/05 15:43:07 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define BASE 0.015
# define MAX 100.0
# define SCALE 0.0001

void	ensure_player_is_in_map(t_cub3D_data *data);
void	do_key(t_cub3D_data *data, int keycode);
void	do_alt_key(t_cub3D_data *data);

#endif
