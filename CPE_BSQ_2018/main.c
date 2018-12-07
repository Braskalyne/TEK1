/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** my main
*/

#include "include/my.h"
#include <unistd.h>

void my_display(char **map, int i, int j, int size)
{
    int k = 0;
    int l = 0;
    int m = j;

    while (k <= size) {
        while (l <= size) {
            map[i][j] = 'x';
            j++;
            l++;
        }
        i++;
        j = m;
        l = 0;
        k++;
    }
}

void remember_my_pos(char **map, int row, int col, int m)
{
    int i = 1;
    int j = 0;
    int size = 0;
    int k = 0;
    int l = 0;

    while (i < row) {
        while (j <= col) {
            size = find_biggest_square(map, row, i, j);
            if (size > k) {
                k = size;
                l = i;
                m = j;
            }
            j++;
        }
        j = 0;
        i++;
    }
    if (k > 0)
        my_display(map, l, m, k);
}

int main(int argc, char **argv)
{
    char **test;
    int size = 1;
    int row = 0;
    int col = 0;
    int pos = 0;

    if (argc == 2) {
        row = nb_rows(argv[1]);
        col = nb_col(argv[1]);
        test = load(test, argv[1], row, col);
        if (col > 1 && row > 1)
            remember_my_pos(test, row, col, pos);
        while (size <= row) {
            write(1, test[size], col + 1);
            size++;
        }
    }
    return (0);
}
