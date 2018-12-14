/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

int char_to_int(char* str);
List *create_a(int nb);
void insertion_a(List *list_a, int nb);
void swap(List *list);
void rotate(List *list, int size);
void switch_a_b(List *list_a, List *list_b);
void switch_b_a(List *list_a, List *list_b);
List *create_b();
void insertion_b(List *list_b, int nb);
void my_algorithm(List *list_a, List *list_b, int size, int size2);
void my_norm(List *list_a, List *list_b, int size, int size2);
