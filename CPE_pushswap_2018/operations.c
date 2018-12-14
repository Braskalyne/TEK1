/*
** EPITECH PROJECT, 2018
** operations
** File description:
** my_operations 
*/

#include "include/struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"

void swap(List *list)
{
    int temp = 0;
    Element *current = list->first;

    temp = current->number;
    current->number = current->next->number;
    current->next->number = temp;
    write(1, "SA", 2);
}

void rotate(List *list, int size)
{
    int temp = 0;
    int i = 0;
    Element *begin = list->first;
    Element *end = list->first;
    
    if (list->first != NULL && list->first->next != NULL) {
        while (i < size) {
            end = end->next;
            i++;
        }
        list->first = begin->next;
        end->next = begin;
        begin->next = NULL;
    }
    write(1, "RA", 2);
}

void switch_a_b(List *list_a, List *list_b)
{
    Element *elem;

    if (list_a->first != NULL) {
        elem = list_a->first;
        if (list_b->first == NULL) {
            list_a->first = elem->next;
            elem->next = NULL;
            list_b->first = elem;
        }
        else {
            list_a->first = elem->next;
            elem->next = list_b->first;
            list_b->first = elem;
        }
    }
    write(1, "PB", 2);
}

void switch_b_a(List *list_a, List *list_b)
{
    Element *elem;

    if (list_b->first != NULL) {
        elem = list_b->first;
        if (list_a->first == NULL) {
            list_b->first = elem->next;
            elem->next = NULL;
            list_a->first = elem;
        }
        else {
            list_b->first = elem->next;
            elem->next = list_a->first;
            list_a->first = elem;
        }
    }
    write(1, "PA", 2);
}