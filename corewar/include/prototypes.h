/*
** EPITECH PROJECT, 2019
** Corewar
** File description:
** No description
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

int args_check(int, char **, char **);
int htoi(char *);
void get_name(unsigned char *, champ_t *);
char *dec_to_hex(unsigned char);
int corewar(champ_t *);
void get_magique_nb(unsigned char *, champ_t *);
void take_infos(champ_t *, char *);
void get_size(unsigned char *, champ_t *);
void get_comment(unsigned char *, champ_t *);
char *map_malloc(void);
void cycle(champ_t *);

#endif /* !PROTOTYPES_H_ */

