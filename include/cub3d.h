/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 14:12:12 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include "../mlx/mlx.h"

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_window
{
	void	*mlx;
	void	*window;
}				t_window;

typedef enum e_map_enum
{
	SPACE,
	WALL,
	VOID,
	NORTH,
	SOUTH,
	WEST,
	EAST,
}			t_map_enum;

typedef struct s_img_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_data
{
	t_map_enum	**map;
	t_window	window;
	t_img_data	img_data;
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	int			floor_color[3];
	int			ceiling_color[3];
}				t_data;

// main programe
int	cub3d(int argc, char **argv);

// init.c

bool	create_window(t_window *window, t_img_data *img_data);

// error.c

void	error_usage(void);
void	error_mlx(void);

// parser.c

void	destroy_map(t_map_enum **map, int height);
bool	parsing_map(char *filepath, t_data *map);

// close_window.c

bool	close_window(t_data *data);
int		handle_key_press(int keycode, t_data *data);
int		handle_window_close(t_data *data);
#endif
