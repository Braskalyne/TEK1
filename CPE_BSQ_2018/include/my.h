/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

void my_putchar(char c);
void my_putnbr(int nb);
void my_putstr(char *str);
int nb_rows(char const *filepath);
int nb_col(char const *filepath);
char **my_malloc(char **dest, int i, int nb_rows, int nb_cols);
char **load(char **dest, char const *filepath, int nb_rows, int nb_cols);
int is_square_of_size(char **map, int row, int col, int square_size);
int find_biggest_square(char **map, int nb_rows, int row, int col);
