/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** counts the lenght of a string
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
