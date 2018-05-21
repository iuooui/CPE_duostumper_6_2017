##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile tail
##

SRC	=	src/utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lingo

all:		$(NAME)

$(NAME):
		gcc -g main.c -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
