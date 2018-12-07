/*
** EPITECH PROJECT, 2018
** bsq.c
** File description:
** my bsq
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char **my_malloc(char **dest, int nb_rows, int nb_cols)
{
    int i = 1;

    dest = malloc(sizeof(char) * (nb_rows * nb_cols));
    while (i <= nb_rows) {
        dest[i] = malloc(sizeof(char) * (nb_rows * nb_cols));
        i++;
    }
    return (dest);
}

char **load(char **dest, char const *filepath, int nb_rows, int nb_cols)
{
    int i = 1;
    int j = 0;
    int fd = 0;
    char buffer[1];

    dest = my_malloc(dest, nb_rows, nb_cols);
    fd = open(filepath, O_RDONLY);
    while (read(fd, buffer, 1) > 0 && buffer[0] != '\n');
    while (i <= nb_rows) {
        while (j <= nb_cols) {
            read(fd, buffer, 1);
            dest[i][j] = buffer[0];
            j++;
        }
        dest[i][j] = '\0';
        j = 0;
        i++;
    }
    close(fd);
    return (dest);
}

int is_square_of_size(char **map, int row, int col, int size, int nb_rows)
{
    int i = col;
    int j = 0;
    int k = 0;

    if ((row + size) > nb_rows)
        return (0);
    while (j <= size) {
        while (k <= size) {
            if (map[row][i] == '.') {
                i++;
                k++;
            }
            else
                return (0);
        }
        i = col;
        j++;
        row++;
        k = 0;
    }
    return (1);
}

int find_biggest_square(char **map, int nb_rows, int row, int col)
{
    int i = col;
    int size = 0;

    while (map[row][i] == '.') {
        i++;
    }
    size = i - col;
    size--;
    while ((is_square_of_size(map, row, col, size, nb_rows) != 1)) {
        size--;
    }
    return (size);
}
