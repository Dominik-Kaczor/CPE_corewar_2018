##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile c files into a binary
## Call the lib's & tests's makefile
##

SC		=		src/

DIR_TEST	=		tests/

SRC		=		$(SC)main.c \
				$(SC)args_checks.c	\
				$(SC)corewar.c	\
				$(SC)malloc_map.c	\
				$(SC)op.c	\
				$(SC)get_magic_size_nb.c	\
				$(SC)get_name_comment.c	\
				$(SC)take_files_infos.c	\
				$(SC)htoi.c	\
				$(SC)cycle.c	\

SRC_TEST		=	$(SC)args_checks.c	\
				$(SC)corewar.c	\
				$(SC)malloc_map.c	\
				$(SC)op.c	\
				$(SC)get_magic_size_nb.c	\
				$(SC)get_name_comment.c	\
				$(SC)take_files_infos.c	\
				$(SC)htoi.c	\
				$(SC)cycle.c	\
				$(DIR_TEST)tests.c	\
				$(DIR_TEST)main_test.c

OBJ		=		$(SRC:.c=.o)

OBJ_TESTS 	=		$(SRC_TESTS:.c=.o)

GCDA		=		$(SRC_TESTS:.c=.gcda)

GCDA2		=		$(GCDA:$(DIR)%=%)

GCDA3		=		$(GCDA2:$(DIR_TEST)%=%)

GCNO		=		$(SRC_TESTS:.c=.gcno)

GCNO2		=		$(GCNO:$(DIR)%=%)

GCNO3		=		$(GCNO2:$(DIR_TEST)%=%)

CFLAGS 		=		-Wall -Wextra

CPPFLAGS 	=		-I./include/

LIB		=		-L../lib/ -lmy

NAME 		=		corewar

NAME_TEST 	=		unit_tests

CC 		=		gcc

RM 		=		rm -rf

LIB_NCURSES 	=		-lncurses

LIB_CRITERION 	= 		--coverage -lcriterion

all:				lib $(NAME)

debug:				CFLAGS += -g3
debug:				re

$(NAME):			$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
				$(RM) $(OBJ)

fclean:			clean lib_clean tests_clean
				$(RM) $(NAME)
				$(RM) $(NAME).dSYM

re:				fclean lib all

tests_run: 			fclean lib $(OBJ_TESTS)
					$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(LIB) $(LIB_CRITERION)
					$(RM) $(OBJ_TESTS)
					./$(NAME_TEST)

tests_clean:
				$(RM) $(NAME_TEST)
				$(RM) *.gcda
				$(RM) *.gcno

lib:
					@make --no-print-directory fclean -C ../lib
					@make --no-print-directory re -C ../lib

lib_clean:
					@make --no-print-directory fclean -C ../lib

.PHONY:				all clean fclean re lib lib_clean tests_run tests_clean
