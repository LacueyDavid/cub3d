/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:33:11 by jugingas          #+#    #+#             */
/*   Updated: 2024/04/06 13:34:38 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_DATA_H
# define IMAGE_DATA_H

#include <aio.h>
#include "libft_and_utils.h"
# include <stdbool.h>

typedef struct s_window
{
	void	*mlx;
	void	*address;
	bool	m_integ;
}				t_window;

typedef struct s_img_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

bool	create_session(t_window *window, t_img_data *img_data);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

#endif
