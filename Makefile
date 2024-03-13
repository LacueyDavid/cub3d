# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 21:05:04 by dlacuey           #+#    #+#              #
#    Updated: 2024/03/13 07:24:30 by dlacuey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lmlx_Linux -Lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

CPPFLAGS =												\
				-I include/								\
														\

OBJS =													\
														\
				$(addprefix srcs/,						\
				main.o									\
														\
				$(addprefix cub3d/,						\
				cub3d.o									\
				)										\
														\
				$(addprefix errors/,					\
				error.o									\
				)										\
														\
				$(addprefix hooks/,						\
				terminate_session.o						\
				key_board_hooks.o						\
				)										\
														\
				$(addprefix initialization/,			\
				create_session.o						\
				)										\
														\
				$(addprefix create_player/,				\
				create_player.o							\
				)										\
														\
				$(addprefix parser/,					\
				parser.o								\
				)										\
														\
				$(addprefix to_sort/,					\
				my_mlx_pixel_put.o						\
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
