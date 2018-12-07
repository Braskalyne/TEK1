/*
** EPITECH PROJECT, 2018
** my_disp_stdarg.c
** File description:
** my_disp_stdarg
*/

#include <stdarg.h>
#include "include/my.h"

void my_display2(va_list ap, int j, char *s)
{
    switch(s[j]) {
        case 'b':
            my_binary(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'S':
            my_stroctal(va_arg(ap, char*));
            break;
        case 's':
            my_putstr(va_arg(ap, char*));
    }
}

void my_display(va_list ap, int j, char *s)
{
    switch(s[j]) {
        case 'X':
            my_upper_hexa(va_arg(ap, int));
            break;
        case 'x':
            my_hexa(va_arg(ap, int));
            break;
        case 'i':
        case 'd':
            my_putnbr(va_arg(ap, int));
            break;
    }
}

int my_check(int j, char *s)
{
    while (s[j] == 32) {
        j++;
    }
    if (s[j] == 'i' || s[j] == 'd')
        my_putchar(' ');
    return (j);
}

int my_double(va_list ap, int j, char *s)
{
    if (s[j + 1] == 'd') {
        my_long_putnbr(va_arg(ap, long long int));
        j = j + 1;
    }
    if (s[j] == '+') {
        my_putchar('+');
        j = j + 1;
        my_display(ap, j, s);
    }
    return (j);
}

int my_printf(char *s, ...)
{
    va_list ap;
    int j = 0;

    va_start(ap, s);
    while (s[j]) {
        if (s[j] == '%') {
            j++;
            j = my_check(j, s);
            my_display(ap, j, s);
            my_display2(ap, j, s);
            j = my_double(ap, j, s);
            j++;
        }
        else { 
            my_putchar(s[j]);
            j++;
        }
    }
    va_end(ap);
    return (0);
}

#include <stdio.h>

int main()
{
    my_printf("%%%%");
    my_putchar('\n');
    printf("%%%%");
    my_putchar('\n');
}
