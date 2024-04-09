# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2024/04/09 15:52:30 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

LDFLAGS = -lmlx_Linux -Lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

CPPFLAGS =												\
				-I include/								\
				-I srcs/gnl/							\
				-I srcs/cub3d/minimap/					\
				-I srcs/errors/							\
				-I srcs/create_player/					\
				-I srcs/parser/							\
				-I srcs/initialization/					\
				-I srcs/utils/							\
				-I srcs/clear/							\
				-I srcs/hooks/							\
				-I mlx/									\
				-I srcs/cub3d/draw/						\
														\
				-MMD -MP -MF $(@:.o=.d)					\
														\

OBJS =													\
														\
				$(addprefix srcs/,						\
				main.o									\
														\
														\
				$(addprefix gnl/,						\
				get_next_line.o							\
				get_next_line_utils.o					\
				)										\
														\
				$(addprefix cub3d/,						\
				cub3d.o									\
														\
				$(addprefix minimap/,					\
				minimap.o								\
				)										\
				$(addprefix draw/,						\
				choose_pixel_texture.o					\
				my_mlx_pixel_put.o						\
				rasterization.o							\
				draw_rays.o								\
				draw_player.o							\
				draw_3d_walls.o							\
				draw_minimap_rays.o						\
				direction_looking.o						\
				draw_help.o								\
				set_rays.o								\
				textured_rasterization.o				\
				)										\
				)										\
														\
				$(addprefix errors/,					\
				error.o									\
				error_2.o								\
				)										\
														\
				$(addprefix hooks/,						\
				mouse_hook.o							\
				terminate_session.o						\
				key_board_hooks.o						\
				do_key.o								\
				bonus_keys.o							\
				movement_key.o							\
				do_movement_key.o						\
				)										\
														\
				$(addprefix initialization/,			\
				create_session.o						\
				)										\
														\
				$(addprefix create_player/,				\
				create_player.o							\
				set_player_first_position.o				\
				)										\
														\
				$(addprefix clear/,						\
				destroy.o								\
				)										\
														\
				$(addprefix parser/,					\
				parser.o								\
				get_textures.o							\
				get_colors.o							\
				get_map.o								\
				get_map_utils.o							\
				check_map.o								\
				check_textures.o						\
				)										\
														\
				$(addprefix utils/,						\
				utils.o									\
				choose_direction.o						\
				color_utils.o							\
				is_lower.o								\
				libft.o									\
				)										\
				)										\
														\

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re check
