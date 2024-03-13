/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/13 07:30:17 by dlacuey          ###   ########.fr       */
/*   Updated: 2024/03/11 15:50:37 by dlacuey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
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

# ifndef W_KEY_CODE
#  define W_KEY_CODE 119
# endif

# ifndef A_KEY_CODE
#  define A_KEY_CODE 97
# endif

# ifndef S_KEY_CODE
#  define S_KEY_CODE 115
# endif

# ifndef D_KEY_CODE
#  define D_KEY_CODE 100
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

typedef struct s_point
{
	int		pos_x;
	int		pos_y;
}			t_point;

typedef struct s_player
{
	t_point	point;
	int		color[3];
	int		size;
}				t_player;

typedef struct s_cub3D_data
{
	t_map_data	map_data;
	t_window	window;
	t_img_data	img_data;
	t_player	player;
}	t_cub3D_data;

// main programe
int		cub3d(t_cub3D_data *data);

// init.c
bool	create_session(t_window *window, t_img_data *img_data);

// create_player.c
bool	create_player(t_player *player);

// close_window.c
bool	terminate_session(t_cub3D_data *data);

// error.c
void	error_usage(void);
void	error_mlx(void);

// parser.c
void	destroy_map(t_map_enum **map, int height);
bool	parsing_map(char *filepath, t_map_data *map);

//hooks

//// hooks to close the window and terminate the program
int		handle_window_close(t_cub3D_data *data);
int		handle_escape_press(int keycode, t_cub3D_data *data);

//// hook to moove the player
bool	key_board_hooks(t_cub3D_data *data);

// put pixel on image
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

//libft.c
void	ft_bzero(void *s, size_t n);

// cub3d.c

#endif
