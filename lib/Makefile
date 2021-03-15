##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## This one, called by the main Makefile with the command make lib, make the
## libmy.a
##

SRC	=		$(wildcard src/*.c)

OBJ	=		$(SRC:.c=.o)

NAME	=	libmy.a

CC	=		gcc

RM	=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
