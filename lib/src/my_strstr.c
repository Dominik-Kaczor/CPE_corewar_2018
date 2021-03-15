/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** No description
*/

#include <stdbool.h>
#include <string.h>

int my_strlen(const char *);
int my_strcmp(const char *, const char *);

bool my_strstr(const char *string, const char *substring)
{
    char *a = NULL;
    char *b = (char *) substring;

    if (*b == 0)
        return (true);
    for (; *string != 0; string += 1) {
        if (*string != *b)
            continue;
        a = (char *) string;
        while (1) {
            if (*b == 0)
                return (true);
            if (*a++ != *b++)
                break;
        }
        b = (char *) substring;
    }
    return (false);
}
