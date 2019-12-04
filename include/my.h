/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** write a header contains prototypes of all functions in libmy.a
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putnbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *str1, char *str2);
int my_strlen(char const *str);
long long my_revnbr(long long nbr);