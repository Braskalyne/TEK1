/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** my struct
*/

typedef struct Element Element;
struct Element
{
    int number;
    Element *next;
};

typedef struct List List;
struct List
{
    Element *first;
};