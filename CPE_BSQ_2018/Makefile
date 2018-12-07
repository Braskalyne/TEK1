##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC =   bsq.c \
        lib/my/my_putstr.c \
        lib/my/my_putnbr.c    \
        lib/my/my_putchar.c    \
        bsq2.c	\
		main.c

OBJ =   $(SRC:.c=.o)

NAME    =   bsq

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
