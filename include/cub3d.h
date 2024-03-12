/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/12 14:49:17 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:50:37 by dlacuey          ###   ########.fr       */
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

# ifndef ESC_KEY_CODE
#  define ESC_KEY_CODE 65307
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

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

typedef struct s_window
{
	void	*mlx;
	void	*address;
}				t_window;

typedef struct s_img_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_map_data
{
	t_map_enum	**map;
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	int			floor_color[3];
	int			ceiling_color[3];
}				t_map_data;

typedef struct s_cub3D_data
{
	t_map_data	map_data;
	t_window	window;
	t_img_data	img_data;
}	t_cub3D_data;

// main programe
int		cub3d(t_cub3D_data *data);

// init.c

bool	create_window(t_window *window, t_img_data *img_data);

// error.c

void	error_usage(void);
void	error_mlx(void);

// parser.c

void	destroy_map(t_map_enum **map, int height);
bool	parsing_map(char *filepath, t_map_data *map);

// close_window.c

bool	close_window(t_cub3D_data *data);
bool	terminate_session(t_cub3D_data *data);

//hooks

int		handle_window_close(t_cub3D_data *data);
int		handle_key_press(int keycode, t_cub3D_data *data);

#endif
