/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:23:31 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/04 12:07:44 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "image_data.h"
# include "cub3d.h"
# include "player.h"

typedef struct ray
{
	float	distance;
	float	distance_v;
	float	distance_h;
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
}			t_ray;

void	rasterization(t_line line, t_img_data *img, int color);
void	textured_rasterization(t_line line, t_img_data *img, t_ray *ray, t_imgs texture);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
bool	reset_image(t_img_data *img_data);
void	draw_minimap(t_cub3D_data *data);
void	draw_player(const t_player player, t_img_data img_data);
void	draw_minimap_2d_ray(t_cub3D_data *data, t_ray *ray);
void	draw_rays(t_cub3D_data *data);
void	looking_left(t_cub3D_data *data, t_ray *ray);
void	looking_right(t_cub3D_data *data, t_ray *ray);
void	looking_up(t_cub3D_data *data, t_ray *ray);
void	looking_down(t_cub3D_data *data, t_ray *ray);
void	looking_straight_sides(t_cub3D_data *data, t_ray *ray, int *bigger);
int		is_wall(t_cub3D_data *data, int x, int y);
float	calculate_ray_distance(t_ray *ray, t_cub3D_data *data);
void	set_current_ray_distance(t_ray *ray, t_cub3D_data *data);
void	draw_3d_walls(t_cub3D_data *data, t_ray *ray);

#endif
