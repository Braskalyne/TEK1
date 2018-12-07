##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC =   my_printf.c \
        my_putstr.c \
        my_putnbr.c    \
        my_putchar.c    \
        my_binary.c \
        my_stroctal.c  \
        my_hexa.c   \
        my_upper_hexa.c	\
		my_long_putnbr.c	\
		my_strlen.c

OBJ =   $(SRC:.c=.o)

NAME    =   libmy.a

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

