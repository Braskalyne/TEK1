##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makes my files
##

SRC    =    create_list_b.c 	\
            operations.c 	\
            pushswap.c

OBJ    =    $(SRC:.c=.o)

NAME    =    push_swap

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re:    fclean all
