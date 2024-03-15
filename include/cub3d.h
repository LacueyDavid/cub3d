/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:43:15 by jugingas          #+#    #+#             */
/*   Updated: 2024/03/15 10:19:24 by dlacuey          ###   ########.fr       */
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
# include "get_next_line.h"

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
	int			width;
	int			height;
	int			minimap_wall_color[3];
	char		*north_img;
	char		*south_img;
	char		*east_img;
	char		*west_img;
	int			floor_color[3];
	int			ceiling_color[3];
}				t_map_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_player
{
	int		orientation;
	t_point	position;
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
bool	create_player(t_player *player, t_map_data *map_data);
void	draw_player(t_cub3D_data *data);
void	set_player_position(t_player *player, t_map_data *map_data);

// close_window.c
bool	terminate_session(t_cub3D_data *data);

// error.c
void	error_wrong_extention(void);
void	error_map_not_found(void);
void	error_parsing(void);
void	error_usage(void);
void	error_mlx(void);

// parser.c
void		destroy_map(t_map_enum **map, int height);
bool		parsing_map(char *filepath, t_map_data *map);
int			skip_texture_and_colors(char **file);
bool		is_map_line(char *line);
int			get_map_size(char **map);
t_map_enum	*fill_with_spaces(t_map_enum *map, int i, int width);
bool		get_textures(char **file, t_map_data *data);
bool		get_colors(char **file, t_map_data *data);
bool		get_map(char **file, t_map_data *data);
bool		check_map(char **map);

//hooks

//// hooks to close the window and terminate the program
int		handle_window_close(t_cub3D_data *data);
int		handle_escape_press(int keycode, t_cub3D_data *data);

//// hook to moove the player
bool	key_board_hooks(t_cub3D_data *data);

// put pixel on image
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

//libft.c
void	print_map(t_map_enum **map, int height, int width);
void	ft_bzero(void *s, size_t n);
bool	is_whitespace(char c);
int		get_number(char *str);
char	*ft_strdup(char *str);
int		rgb_to_int(int color_rgb[3]);
bool	reset_image(t_cub3D_data *data);
int		ft_strlen(const char *s);

// cub3d.c

//// minimap.c
void	draw_minimap(t_cub3D_data *data);

#endif
