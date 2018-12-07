##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makes my files
##

SRC    =	sokoban.c 	\
			switch.c 	\
			main.c	

OBJ    =    $(SRC:.c=.o)

NAME    =    my_sokoban

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC) -lncurses

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:    fclean all
