/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

int my_rules(char *str);
int my_col(char const *filepath);
int my_row(char const *filepath);
char **my_malloc(char **memory, int row, int col);
char **load(char **dest, char const *filepath, int row, int col);
int main(int argc, char **argv);
int my_sokoban(char **map, char **argv, int row, int col);
char** my_call_switch(char **map, char **argv, int row, int col);
void case_a(char **map, int row, int col);
void case_b(char **map, int row, int col);
void case_c(char **map, int row, int col);
void case_d(char **map, int row, int col);
