/*
** EPITECH PROJECT, 2018
** my_hupper_hexa
** File description:
** display in hexa uppercase
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

void my_upper_hexa(unsigned int nb)
{
    int i = 0;
    int *tab;
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
        my_upper(tab, i);
        i--;
    }
}

void my_upper(unsigned int *tab, int i)
{
    if (tab[i] < 10)
        my_putnbr(tab[i]);
    if (tab[i] == 10)
        my_putchar('A');
    if (tab[i] == 11)
        my_putchar('B');
    if (tab[i] == 12)
        my_putchar('C');
    if (tab[i] == 13)
        my_putchar('D');
    if (tab[i] == 14)
        my_putchar('E');
    if (tab[i] == 15)
        my_putchar('F');
}
