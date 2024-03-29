# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumseo <sumseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:31:45 by sumseo            #+#    #+#              #
#    Updated: 2024/02/22 12:50:44 by sumseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#
#SRCS and OBJS
#
SRCS = minirt.c get_next_line.c get_next_line_utils.c key_events.c utils/map_parsing.c utils/map_error_handler.c utils/utils.c utils/map_image_handler.c utils/map_parsing_handler.c
INCLUDES = minilibx/
INCLUDES2 =printf/
OBJS = $(SRCS:%.c=%.o)

#
#Compiler and flags
#

CC = clang
CFLAGS = -Wall -Werror -Wextra -g3
CLIB = -Lminilibx/ -lmlx -lmlx_Linux -Iminilibx -lX11 -lXext -Lprintf/ -lftprintf
DEBUGGER = -g3


all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DEBUGGER)

$(NAME) : $(OBJS)
	make -C minilibx
	make -C printf
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(INCLUDES2) $(OBJS) -o $(NAME) $(CLIB) $(DEBUGGER)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
