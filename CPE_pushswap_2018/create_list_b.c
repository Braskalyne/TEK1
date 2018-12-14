/*
** EPITECH PROJECT, 2018
** create_list_b.c
** File description:
** create my list_b
*/

#include "include/struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

List *create_b()
{
    List *list_b;

    list_b = malloc(sizeof(*list_b));
    list_b->first = NULL;
    return (list_b);
}

void insertion_b(List *list_b, int nb)
{
    Element *temp;
    Element *new;

    new = malloc(sizeof(*new));
    new->number = nb;
    new->next = NULL;
    temp = list_b->first;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void my_algorithm(List *list_a, List *list_b, int size, int size2)
{
    Element *current;
    int i = 0;

    while (i < size)     {
        current = list_a->first;
        if (current->number > current->next->number) {
            rotate(list_a, size);
            write(1, " ", 1);
        }
        else if (current->number <= current->next->number) {
            swap(list_a);
            write(1, " ", 1);
            rotate(list_a, size);
            write(1, " ", 1);
        }
        i++;
    }
    my_norm(list_a, list_b, size, size2);
}

void my_norm(List *list_a, List *list_b, int size, int size2)
{
    int i = 0;

    switch_a_b(list_a, list_b);
    write(1, " ", 1);
    if (size > 0)
        my_algorithm(list_a, list_b, (size - 1), size2);
    while (i <= size) {
        switch_b_a(list_a, list_b);
        if (i == size2)
            write(1, "\n", 1);
        else
            write(1, " ", 1);
        i++;
    }
}