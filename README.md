# FDF
Create simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments(edges).

## Mandatory Conditions
1. By using MiniLibx,I have to parse map and draw the image with isometric projection. 
2. What is Isometric projection ? 동축투영법으로 3차원 물체를 2차원에 표현하기 위한 투영법중에 하나이다. 
3. Makefile : Compile sources files including MiniLibx

#### Makefile
1. First, it is better to create makefile to compile all the files ane the MiniLibx library.
2. At 42Paris, we are using ubuntu machine. So I choosed the second one among three libraries.
3. NAME = fdf : The compiling command will be "fdf", by default it is a.out -> ./fdf will be the final excutable command
4. SRCS = minirt.c : this file has main function so it will be compiled
5. INCLUDES = minilibx : Include this library 
6. OBJS = $(SRCS:%.c=%.o) : Compile all these files which end .c and make it as .o
7. CC = clang : compile command
8. CFLAGS = -Wall -Werror -Wextra : Add flags
9. CLIB = -Lminilibx/ -lmlx -lmlx_Linux -Iminilibx -lx11 -lXext : "L"ocate to the directory and "l"ocate to mlx.a mlx_Linux.a and find the file which ends "h" with I command
10. all : $(NAME) -> This command is same as make
11. $.o : %.c
12. $(NAME) : $(OBJS)
13. clean : rm -rf $(OBJS)
14. fclean : clean / rm-rf $(NAME)
15. re : fclean all