/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** warehouse keeper
*/

#include <unistd.h>
#include "include/my.h"
#include <ncurses.h>
#include "include/struct.h"
#include <stdlib.h>

int my_rules(char *str)
{
    if (str[0] == '-' && str[1] == 'h') {
        write(1, "USAGE\n       ./my_sokoban map\nDESCRIPTION\n", 42);
        write(1, "       map file representing the warehouse map", 46);
        write(1, " containing '#' for walls,\n         'P' for the play", 52);
        write(1, "er 'X' for boxes and 'O' for storage locations.\n", 48);
        return (1);
    }
    return (0);
}

int my_finish(char **map, int row, int col)
{
    int i = 0;  
    int j = 0;

    while (i < row) {
        while (j < col) {
            if (map[i][j] == 'O')
                return (0);
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

char** my_call_switch(char **map, char **argv, int row, int col)
{
    keypad(stdscr, TRUE);
    int ch = getch();
    switch(ch) {
        case KEY_UP:
            case_a(map, row, col);
            break;
        case KEY_DOWN:
            case_b(map, row, col);
            break;
        case KEY_RIGHT:
            case_c(map, row, col);
            break;
        case KEY_LEFT:
            case_d(map, row, col);
            break;
        case ' ':
            map = load(map, argv[1], row, col);
            break;
    }
    return (map);
}

void my_display(char **map, int row)
{
    int size = 0;

    while (size < row) {
        mvprintw(size, 0, map[size]);
        size++;
    }
}

int my_sokoban(char **map, char **argv, int row, int col)
{
    Position Player;

    initscr();
    noecho();
    my_display(map, row);
    while (1) {
        map = my_call_switch(map, argv, row, col);
        my_display(map, row);
        refresh();
        if (my_finish(map, row, col) == 1) {
            endwin();
            exit(0);
        }
    }
}