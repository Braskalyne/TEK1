/*
** EPITECH PROJECT, 2018
** my_hexa.c
** File description:
** display in hexa
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

void my_hexa(unsigned int nb)
{
    int i = 0;
    int *tab;
    int result = 0;
    int modulo = 0;

    if (nb == 0)
        my_putchar('0');
    tab = malloc(sizeof(unsigned int) * nb);
    while (nb > 0) {
        modulo = nb % 16;
        nb = nb / 16;
        tab[i] = modulo;
        i++;
    }
    i--;
    while (i > -1) {
        my_disp(tab, i);
        i--;
    }
}

void my_disp(unsigned int *tab, int i)
{
    if (tab[i] < 10)
        my_putnbr(tab[i]);
    if (tab[i] == 10)
        my_putchar('a');
    if (tab[i] == 11)
        my_putchar('b');
    if (tab[i] == 12)
        my_putchar('c');
    if (tab[i] == 13)
        my_putchar('d');
    if (tab[i] == 14)
        my_putchar('e');
    if (tab[i] == 15)
        my_putchar('f');
}
