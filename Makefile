##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	lib/my/my_getnbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putnbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revnbr.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strncpy.c	\

SRC2 =	src/main.c	\
		src/get_map.c	\
		src/boats_in_map.c	\
		src/connect_players.c	\
		src/player.c	\
		src/utilities.c	\
		src/hit_or_miss.c	\

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a

NAME2 =	navy

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME2) $(SRC2) -g3 -L. libmy.a

clean:
	rm $(OBJ)

fclean:
	rm -f $(NAME2)
	rm -f $(NAME)
	rm $(OBJ)

re:	fclean all
