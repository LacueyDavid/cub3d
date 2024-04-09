/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:23:31 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 15:02:36 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "image_data.h"
# include "cub3d.h"
# include "player.h"
# include "ray.h"

typedef struct rasterization
{
	int			error;
	int			err2;
	t_point		diff;
	t_point		direction;
}				t_rasterization;

void	rasterization(t_line line, t_img_data *img, int color);
void	textured_rasterization(t_line line, t_img_data *img,
			t_ray *ray, t_cub3d_data *data);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
bool	reset_image(t_img_data *img_data);
void	draw_minimap(t_cub3d_data *data);
void	draw_player(const t_player player, t_img_data img_data);
void	draw_minimap_2d_ray(t_cub3d_data *data, t_ray *ray);
void	draw_rays(t_cub3d_data *data);
void	looking_left(t_cub3d_data *data, t_ray *ray);
void	looking_right(t_cub3d_data *data, t_ray *ray);
void	looking_up(t_cub3d_data *data, t_ray *ray);
void	looking_down(t_cub3d_data *data, t_ray *ray);
void	looking_straight_sides(t_cub3d_data *data, t_ray *ray, int *bigger);
int		is_wall(t_cub3d_data *data, int x, int y);
float	calculate_ray_distance(t_ray *ray, t_cub3d_data *data);
void	set_current_ray_distance(t_ray *ray, t_cub3d_data *data);
void	draw_3d_walls(t_cub3d_data *data, t_ray *ray);
void	textured_rasterization(t_line line, t_img_data *img,
			t_ray *ray, t_cub3d_data *data);
void	choose_pixel_texture(t_ray *ray, t_pixel_extractor *extractor,
			t_cub3d_data *data);
int		get_pixel_color(t_imgs img, int x, int y);

#endif
