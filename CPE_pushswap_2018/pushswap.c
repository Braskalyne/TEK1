/*
** EPITECH PROJECT, 2018
** pushswap.c
** File description:
** sort linked list
*/

#include "include/struct.h"
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int char_to_int(char* str)
{
    int i = 0;
    int result = 0;

    while (str[i]) {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result);
}

List *create_a(int nb)
{
    List *list_a;
    Element *maillon;

    list_a = malloc(sizeof(*list_a));
    maillon = malloc(sizeof(*maillon));
    maillon->number = nb;
    maillon->next = NULL;
    list_a->first = maillon;
    return (list_a);
}

void insertion_a(List *list_a, int nb)
{
    Element* temp;
    Element* new;

    new = malloc(sizeof(*new));
    new->number = nb;
    new->next = NULL;
    temp = list_a->first;
    while (temp->next != NULL)
        temp = temp->next; 
    temp->next = new;
}

int main(int argc, char **argv)
{
    List *list_a = malloc(sizeof(*list_a));
    List *list_b = malloc(sizeof(*list_b));
    if (argc > 2) {
        int size = (argc - 2);
        int stop = 2;
        int i = 0;

        i = char_to_int(argv[1]);
        list_a = create_a(i);
        list_b = create_b();
        while (stop < argc) {
            i = char_to_int(argv[stop]);
            insertion_a(list_a, i);
            stop++;
        }
        my_algorithm(list_a, list_b, size, size);
    }
    return (0);
}