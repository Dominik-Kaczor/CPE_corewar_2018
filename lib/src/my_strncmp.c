/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** No description
*/

int my_strncmp(const char *s1, const char *s2, int len)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] && s2[i] && i < len; i++) {
        if ((s1[i] == '\0' && s2[i] == '\0') || i == len)
            return (0);
        else if (s1[i] > s2[i])
            return (1);
    }
    return (1);
}
