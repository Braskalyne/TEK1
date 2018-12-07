/*
** EPITECH PROJECT, 2018
** my_binary.c
** File description:
** print a number in binary
*/

#include "include/my.h"
#include <stdlib.h>

void my_binary(unsigned int nb)
{
    int i = 0;
    int *tab;
    int result = 0;
    int modulo = 0;

    if (nb == 0)
        my_putchar('0');
    tab = malloc(sizeof(unsigned int) * nb);
    while (nb > 0) {
        modulo = nb % 2;
        nb = nb / 2;
        tab[i] = modulo;
        i++;
    }
    i--;
    while (i > -1) {
        my_putnbr(tab[i]);
        i--;
    }
}
