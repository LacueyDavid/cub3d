/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:23:31 by dlacuey           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:12 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "image_data.h"
# include "player.h"
# include "cub3d.h"

void	rasterization(t_line line, t_img_data *img, int color);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
bool	reset_image(t_img_data *img_data);
void	draw_minimap(t_cub3D_data *data);
void	draw_player(const t_player player, t_img_data img_data);

#endif
