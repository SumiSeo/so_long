CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g3
SOURCE = ft_printf.c ft_putchar.c ft_putnbr.c ft_putmnbr.c \
			ft_putptr.c ft_putstr.c 
OBJ = $(SOURCE:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ) 

fclean : clean
	$(RM) $(NAME)

re: fclean all
