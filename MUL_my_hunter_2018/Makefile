##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC =	my_hunter.c   

OBJ =   $(SRC:.c=.o)

NAME    =   my_hunter

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o my_hunter my_hunter.c -l csfml-graphics -l csfml-system -l csfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

