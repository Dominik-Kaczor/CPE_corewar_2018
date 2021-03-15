##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile c files into a binary
## Call the lib's & tests's makefile
##

all:	lib asm corewar

fclean:	clean

re:		fclean all

lib:
		@make --no-print-directory fclean -C ./lib
		@make --no-print-directory re -C ./lib

asm:
		@make --no-print-directory fclean -C ./asm
		@make --no-print-directory re -C ./asm

corewar:
		@make --no-print-directory fclean -C ./corewar
		@make --no-print-directory re -C ./corewar

clean:
		@make --no-print-directory fclean -C ./lib
		@make --no-print-directory fclean -C ./corewar
		@make --no-print-directory fclean -C ./asm

tests_run: lib
		@make --no-print-directory tests_run -C ./asm
		@make --no-print-directory tests_run -C ./corewar

tests_clean:
		@make --no-print-directory tests_clean -C ./asm

.PHONY:	all clean fclean re lib asm corewar
