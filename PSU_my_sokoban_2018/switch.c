/*
** EPITECH PROJECT, 2018
** switch
** File description:
** switch keys
*/

#include <unistd.h>
#include "include/my.h"
#include <ncurses.h>
#include "include/struct.h"
#include <stdlib.h>

Position my_position(char **map, int row, int col)
{
    int i = 0;
    int j = 0;
    Position Player;

    while (i < row) {
        while (j < col) {
            if (map[i][j] == 'P') {
                Player.x = i;
                Player.y = j;
                return (Player);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void case_a(char **map, int row, int col)
{
	Position Player;

	Player = my_position(map, row, col);
	if (map[Player.x - 1][Player.y] == ' ') {
  		map[Player.x][Player.y] = ' ';
        map[Player.x - 1][Player.y] = 'P'; 
    }
    else if (map[Player.x - 1][Player.y] == 'X') {
        if (map[Player.x - 2][Player.y] == ' ' ||
        	map[Player.x - 2][Player.y] == 'O') {
            map[Player.x - 1][Player.y] = 'P';
            map[Player.x - 2][Player.y] = 'X';
            map[Player.x][Player.y] = ' ';
        }
    }
}

void case_b(char **map, int row, int col)
{
	Position Player;

	Player = my_position(map, row, col);
	if (map[Player.x + 1][Player.y] == ' ') {
        map[Player.x][Player.y] = ' ';
        map[Player.x + 1][Player.y] = 'P';
    }
    else if (map[Player.x + 1][Player.y] == 'X') {
        if (map[Player.x + 2][Player.y] == ' ' ||
            map[Player.x + 2][Player.y] == 'O') {
            map[Player.x + 1][Player.y] = 'P';
            map[Player.x + 2][Player.y] = 'X';
            map[Player.x][Player.y] = ' ';
        }
    }
}

void case_c(char **map, int row, int col)
{
    Position Player;

    Player = my_position(map, row, col);
    if (map[Player.x][Player.y + 1] == ' ') {
        map[Player.x][Player.y] = ' ';
        map[Player.x][Player.y + 1] = 'P';
    }
    else if (map[Player.x][Player.y + 1] == 'X') {
        if (map[Player.x][Player.y + 2] == ' ' ||
            map[Player.x][Player.y + 2] == 'O') {
            map[Player.x][Player.y + 1] = 'P';
            map[Player.x][Player.y + 2] = 'X';
            map[Player.x][Player.y] = ' ';
        }
    }
}

void case_d(char **map, int row, int col)
{
    Position Player;

    Player = my_position(map, row, col);
    if (map[Player.x][Player.y - 1] == ' ') {
        map[Player.x][Player.y] = ' ';
        map[Player.x][Player.y - 1] = 'P';
    }
    else if (map[Player.x][Player.y - 1] == 'X') {
        if (map[Player.x][Player.y - 2] == ' ' ||
            map[Player.x][Player.y - 2] == 'O') {
            map[Player.x][Player.y - 1] = 'P';
            map[Player.x][Player.y - 2] = 'X';
            map[Player.x][Player.y] = ' ';
        }
    }
}