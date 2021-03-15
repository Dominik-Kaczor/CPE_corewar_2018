##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile c files into a binary
## Call the lib's & tests's makefile
##

SC		=			src/

DIR_COMPILER 	=			compiler

DIR_TEST	=			tests/

SRC		=			$(SC)op.c \
					$(SC)main.c \
					$(SC)help.c \
					$(SC)path_handler.c \
					$(SC)file_check.c	\
					$(SC)input_processing.c	\
					$(SC)get_champion.c	\
					$(SC)useful_fonctions.c	\
					$(SC)get_name_and_com.c	\
					$(SC)get_label.c	\
					$(SC)get_instruction.c	\
					$(SC)check_parameter.c	\
					$(SC)write_to_file.c \
					$(SC)get_size_prog.c \
					$(SC)check_direct.c \
					$(SC)separate_params.c \
					$(SC)check_register.c \
					$(SC)check_name_com.c \
					$(SC)write_instructions.c \
					$(SC)stick_params.c \
					$(SC)useful_fonctions_two.c

SRC_TESTS	=		$(DIR_TEST)tests_of_corewar.c \
					$(SC)op.c \
					$(SC)help.c \
					$(SC)path_handler.c \
					$(SC)file_check.c	\
					$(SC)input_processing.c	\
					$(SC)get_champion.c	\
					$(SC)useful_fonctions.c	\
					$(SC)get_name_and_com.c	\
					$(SC)get_label.c	\
					$(SC)get_instruction.c	\
					$(SC)check_parameter.c	\
					$(SC)write_to_file.c \
					$(SC)get_size_prog.c \
					$(SC)check_direct.c \
					$(SC)separate_params.c \
					$(SC)check_register.c \
					$(SC)write_instructions.c \
					$(SC)check_name_com.c \
					$(SC)stick_params.c \
					$(SC)useful_fonctions_two.c

OBJ		=			$(SRC:.c=.o)

OBJ_TESTS 	=			$(SRC_TESTS:.c=.o)

GCDA		=			$(SRC_TESTS:.c=.gcda)

GCDA2		=			$(GCDA:$(DIR)%=%)

GCDA3		=			$(GCDA2:$(DIR_TEST)%=%)

GCNO		=			$(SRC_TESTS:.c=.gcno)

GCNO2		=			$(GCNO:$(DIR)%=%)

GCNO3		=			$(GCNO2:$(DIR_TEST)%=%)

CFLAGS 		=			-Wall -Wextra

CPPFLAGS 	=			-I./include/

LIB		=			-L../lib/ -lmy

NAME 		=			asm

NAME_TEST 	=			unit_tests

CC 		=			gcc

RM 		=			rm -rf

LIB_NCURSES 	=			-lncurses

LIB_CRITERION 	= 			--coverage -lcriterion

all:					lib $(NAME)

debug:					CFLAGS += -g3
debug:					re

$(NAME):			$(OBJ)
					$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
					$(RM) $(OBJ)

fclean:				clean lib_clean tests_clean
					$(RM) $(NAME)
					$(RM) $(NAME).dSYM

re:					fclean lib all

tests_run:	 			fclean lib $(OBJ_TESTS)
					$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TESTS) $(LIB) $(LIB_CRITERION)
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
