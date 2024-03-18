# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2024/03/18 14:17:24 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lmlx_Linux -Lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

CPPFLAGS =												\
				-I include/								\
				-I srcs/get_next_line/					\
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

OBJS =													\
														\
				$(addprefix srcs/,						\
				main.o									\
														\
														\
				$(addprefix get_next_line/,				\
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
				my_mlx_pixel_put.o						\
				rasterization.o							\
				draw.o									\
				)										\
				)										\
														\
				$(addprefix errors/,					\
				error.o									\
				error_2.o								\
				)										\
														\
				$(addprefix hooks/,						\
				terminate_session.o						\
				key_board_hooks.o						\
				do_key.o								\
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
				)										\
														\
				$(addprefix utils/,						\
				utils.o									\
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

.PHONY: all clean fclean re check
