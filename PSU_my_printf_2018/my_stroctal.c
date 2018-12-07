/*
** EPITECH PROJECT, 2018
** my_stroctal
** File description:
** display a string with octal value
*/

#include "include/my.h"
#include <stdlib.h>

void my_stroctal(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] >= 32 && str[i] < 127)
            my_putchar(str[i]);
        if (str[i] >= 127) {
            my_putchar('\\');
            my_octal(str[i]);
        }
        if (str[i] >= 0 && str[i] <= 7) {
            my_putstr("\\00");
            my_octal(str[i]);
        }
        if (str[i] >= 8 && str[i] < 32) {
            my_putstr("\\0");
            my_octal(str[i]);
        }
        i++;
    }
}

void my_octal(unsigned int nb)
{
    int i = 0;
    int *tab;
    int result = 0;
    int modulo = 0;

    if (nb == 0)
        my_putstr("000");
    tab = malloc(sizeof(unsigned int) * nb);
    while (nb > 0) {
        modulo = nb % 8;
        nb = nb / 8;
        tab[i] = modulo;
        i++;
    }
    i--;
    while (i > -1) {
        my_putnbr(tab[i]);
        i--;
    }
}
