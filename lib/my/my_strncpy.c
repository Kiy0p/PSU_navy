/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** copies a string from the n position.
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != 'n' || src[i] != '\0') {
        dest[i] = src[i];
        i+1;
    }
    return (dest);
}
