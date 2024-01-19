# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:31:45 by sumseo            #+#    #+#              #
#    Updated: 2024/01/09 16:38:06 by sumseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#
#SRCS and OBJS
#
SRCS = minirt.c get_next_line.c get_next_line_utils.c send_error_msg.c key_events.c utils/map_parsing.c
INCLUDES = minilibx/
INCLUDES2 =printf/
OBJS = $(SRCS:%.c=%.o)

#
#Compiler and flags
#

CC = clang
CFLAGS = -Wall -Werror -Wextra
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
