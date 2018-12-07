/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** warehouse keeper
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/struct.h"
#include <ncurses.h>

int my_col(char const *filepath)
{
    char buffer[1];
    int fd = 0;
    int col = 0;

    fd = open(filepath, O_RDONLY);
    while ((read(fd, buffer, 1) > 0) && buffer[0] != '\n') {
        col++;
    }
    return (col);
}

int my_row(char const *filepath)
{
    char buffer[1];
    int fd = 0;
    int row = 0;

    fd = open(filepath, O_RDONLY);
    while ((read(fd, buffer, 1) > 0)) {
        if (buffer[0] == '\n') {
            row++;
        }
    }
    return (row);
}

char **my_malloc(char **memory, int row, int col)
{
    int i = 0;

    memory = malloc(sizeof(char) * (row * col));
    while (i <= row) {
        memory[i] = malloc(sizeof(char) * (row * col));
        i++;
    }
    return (memory);
}

char **load(char **dest, char const *filepath, int row, int col)
{
    int i = 0;
    int j = 0;
    int fd = 0;
    char buffer[1];

    dest = my_malloc(dest, row, col);
    fd = open(filepath, O_RDONLY);
    while (i <= row) {
        while (j <= col) {
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

int main(int argc, char **argv)
{
    int row = 0;
    int col = 0;
    int size = 0;
    char **map;

    if (argc == 2) {
        if (my_rules(argv[1]) == 1)
            exit(0);
        col = my_col(argv[1]);
        row = my_row(argv[1]);
        map = load(map, argv[1], row, col);
        my_sokoban(map, argv, row, col);
    }
    return (0);
}