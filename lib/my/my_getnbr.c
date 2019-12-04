/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** converts an char * into an int
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (84);
        nbr = nbr + str[i] - 48;
        nbr = nbr * 10;
        i++;
    }
    nbr /= 10;
    if (str[0] == '-')
        return (-1 * nbr);
    else
        return (nbr);
}
