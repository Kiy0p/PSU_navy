/*
** EPITECH PROJECT, 2018
** MY_PUTSTR
** File description:
** CPool Day04 Task02
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1) {
        my_putchar (str[i]);
    }
}
