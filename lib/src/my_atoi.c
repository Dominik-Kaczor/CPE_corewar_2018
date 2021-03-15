/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** Convert a string into integer
*/

int my_atoi(char *str)
{
    int number = 0;

    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        number = number * 10 + (str[i] - '0');
    return (number);
}
