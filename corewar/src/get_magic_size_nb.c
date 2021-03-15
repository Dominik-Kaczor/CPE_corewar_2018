/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** functions used to get file magic nb
*/

#include "corewar.h"

char *fill_hex(void)
{
    char *hex = malloc(sizeof(char) * 3);

    hex[0] = '0';
    hex[1] = '0';
    hex[2] = 0;
    return (hex);
}

char *dec_to_hex(unsigned char nb)
{
    char *hex = fill_hex();
    int tmp = 0;

    if (nb < 16) {
        if (nb < 10)
            hex[1] = (nb + 48);
        else
            hex[1] = (nb + 87);
        return (hex);
    }
    for (int i = 1; nb != 0; i--) {
        tmp = nb % 16;
        if (tmp < 10)
            hex[i] = (tmp + 48);
        else
            hex[i] = (tmp + 87);
        nb = nb / 16;
    }
    return (hex);
}

void add_to_m_nb(champ_t *champ, char *hex)
{
    int i = 0;

    while (champ->m_nb[i] != '0')
        i++;
    champ->m_nb[i] = hex[1];
    champ->m_nb[i + 1] = hex[0];
}

void get_magique_nb(unsigned char *buffer, champ_t *champ)
{
    champ->pos = 0;
    champ->m_nb = "0x";
    while (buffer[champ->pos] == 0)
        champ->pos++;
    champ->m_nb = my_strcat(champ->m_nb, dec_to_hex(buffer[champ->pos++]));
    champ->m_nb = my_strcat(champ->m_nb, dec_to_hex(buffer[champ->pos++]));
    champ->m_nb = my_strcat(champ->m_nb, dec_to_hex(buffer[champ->pos++]));
    if (!my_strcmp(champ->m_nb, STR_MAGIC)) {
        write(2, "Error: Wrong magic nb!\n", 23);
        exit(84);
    }
}

void get_size(unsigned char *buffer, champ_t *champ)
{
    char *nb = "";

    champ->pos = 136;
    nb = my_strcat(nb, dec_to_hex(buffer[champ->pos++]));
    nb = my_strcat(nb, dec_to_hex(buffer[champ->pos++]));
    nb = my_strcat(nb, dec_to_hex(buffer[champ->pos++]));
    nb = my_strcat(nb, dec_to_hex(buffer[champ->pos++]));
    champ->size = htoi(nb);
}
