/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** prints out numbers
*/

#include "../../include/my.h"

int my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * - 1;
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar('0' + (nb % 10));
}
