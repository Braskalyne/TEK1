/*
** EPITECH PROJECT, 2018
** bsq2
** File description:
** bsq2
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"

int nb_rows(char const *filepath)
{
    char buffer[1];
    int fd = 0; 
    int result = 0;

    fd = open(filepath, O_RDONLY);
    while ((read(fd, buffer, 1) > 0) && buffer[0] != '\n') {
        if (buffer[0] >= '0' && buffer[0] <= '9')
            result = (result * 10 + (buffer[0] - 48));
        else if (buffer[0] < 48 || buffer[0] > 57) 
            return (-1);
        }
    close(fd);
    return (result);
}

int nb_col(char const *filepath)
{
    char buffer[1];
    int fd; 
    int i;

    fd = open(filepath, O_RDONLY);
    while ((read(fd, buffer, 1) > 0) && buffer[0] != '\n')
        i++;
    i = 0;
    while ((read(fd, buffer, 1) > 0) && buffer[0] != '\n')
        i++;
    close(fd);
    return (i);
}
