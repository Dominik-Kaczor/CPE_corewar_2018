/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** create again the printf program in the C lib
*/

#include <stdarg.h>
#include <stdio.h>

int easy_flags_management(int, va_list);
void my_putchar(char);
void my_putnbr(int);
void my_putstr(char *);
void my_putstr_term_key(char *);

int easy_flags_management(int argument, va_list display)
{
    switch (argument){
    case 'c':
        my_putchar(va_arg(display, int));
        break;
    case 'd':
        my_putnbr(va_arg(display, int));
        break;
    case 's':
        my_putstr(va_arg(display, char *));
        break;
    case 'k':
        my_putstr_term_key(va_arg(display, char *));
        break;
    }
    return (0);
}

void my_printf(char *str, ...)
{
    int i = 0;
    int argument;
    va_list display;

    va_start(display, str);
    while (str[i] != '\0'){
        if (str[i] == '%'){
            i++;
            argument = str[i];
            easy_flags_management(argument, display);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
    va_end(display);
    return;
}
