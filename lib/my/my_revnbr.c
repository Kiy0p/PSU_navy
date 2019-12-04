/*
** EPITECH PROJECT, 2018
** my_revnbr.c
** File description:
** reverse a number
*/

#include "../../include/my.h"

long long my_revnbr(long long nbr)
{
    long long rev_nbr = 0;

    if (nbr >= 0) {
        while (nbr > 0)
        {
            rev_nbr = rev_nbr * 10 + nbr % 10;
            nbr = nbr / 10;
        }
    }
    else {
        while (nbr < 0)
        {
            rev_nbr = rev_nbr * 10 + nbr % 10;
            nbr = nbr / 10;
        }
    }
    return (rev_nbr);
}
