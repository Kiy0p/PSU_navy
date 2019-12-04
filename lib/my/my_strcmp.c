/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** compares two strings. returns an integrer. if return > 0 str1 > str2
*/

#include "../../include/my.h"

int my_strcmp(char *str1, char *str2)
{
    int bytes_one = my_strlen(str1);
    int bytes_two = my_strlen(str2);

    if (bytes_one > bytes_two)
        return (1);
    if (bytes_one < bytes_two)
        return (-1);
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == str2[i])
            bytes_one--;
    }
    return (bytes_one);
}
