/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/07 14:59:40 by dlacuey          ###   ########.fr       */
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

typedef struct s_map
{
	t_map_enum	**map;
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	int			floor_color[3];
	int			ceiling_color[3];
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

// main programe
int	cub3d(int argc, char **argv);

// init.c

bool	create_window(t_window *window);
bool	init_img(t_window *window, t_img *img);

// error.c

void	error_usage(void);
void	error_mlx(void);

// parser.c

bool	parsing_map(char *filepath, t_map *map);

// close_window.c

bool	close_window(t_window *window);
int	handle_key_press(int keycode, t_window *window);
int	handle_window_close(t_window *window);
#endif
