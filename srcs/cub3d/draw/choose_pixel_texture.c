/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_pixel_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlacuey <dlacuey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:09:42 by dlacuey           #+#    #+#             */
/*   Updated: 2024/04/09 14:11:23 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(t_imgs img, int x, int y)
{
	int	color;

	color = *(int *)(img.data.address + (y * img.data.line_length + x
				* (img.data.bits_per_pixel / 8)));
	return (color);
}

static void	take_pixel_texture(t_imgs texture,
		t_pixel_extractor *extractor, t_ray *ray, float ray_coordinate)
{
	extractor->gap = extractor->map_gap * texture.width;
	extractor->texture = texture;
	extractor->color = get_pixel_color(texture,
			extractor->position_x, extractor->position_y);
	extractor->position_y = (extractor->ecart
			+ (extractor->line_p1_y - extractor->start_y))
		* extractor->texture.height / ray->line_height;
	if (extractor->position_y < 0)
		extractor->position_y = 0;
	if (extractor->position_y >= texture.height)
		extractor->position_y = texture.height - 1;
	extractor->position_x = ((int)(ray_coordinate * texture.width)
			% extractor->gap) * texture.width / extractor->gap;
	if (extractor->position_x < 0)
		extractor->position_x = 0;
	if (extractor->position_x >= texture.width)
		extractor->position_x = texture.width - 1;
}

void	choose_pixel_texture(t_ray *ray,
		t_pixel_extractor *extractor, t_cub3D_data *data)
{
	t_imgs	texture_north;
	t_imgs	texture_south;
	t_imgs	texture_west;
	t_imgs	texture_east;

	texture_north = data->map_data.img[NORTH];
	texture_south = data->map_data.img[SOUTH];
	texture_west = data->map_data.img[WEST];
	texture_east = data->map_data.img[EAST];
	if (is_a_north_wall(ray))
		take_pixel_texture(texture_north, extractor, ray, ray->x);
	else if (is_a_west_wall(ray))
		take_pixel_texture(texture_west, extractor, ray, ray->y);
	else if (is_a_east_wall(ray))
		take_pixel_texture(texture_east, extractor, ray, ray->y);
	else
		take_pixel_texture(texture_south, extractor, ray, ray->x);
}
