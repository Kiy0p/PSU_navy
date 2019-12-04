/*
** EPITECH PROJECT, 2019
** get_map.c
** File description:
** gets the map for the navy
*/

#include "../include/my.h"
#include "../include/my_navy.h"

void print_map(char **map)
{
    for (int i = 0; i < 10; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

char **put_in_map(char **map)
{
    my_strcpy(map[0], " |A B C D E F G H");
    my_strcpy(map[1], "-+---------------");
    my_strcpy(map[2], "1|. . . . . . . .");
    my_strcpy(map[3], "2|. . . . . . . .");
    my_strcpy(map[4], "3|. . . . . . . .");
    my_strcpy(map[5], "4|. . . . . . . .");
    my_strcpy(map[6], "5|. . . . . . . .");
    my_strcpy(map[7], "6|. . . . . . . .");
    my_strcpy(map[8], "7|. . . . . . . .");
    my_strcpy(map[9], "8|. . . . . . . .");
    return (map);
}

char **get_map(void)
{
    int rows = 10;
    int cols = 18;
    char **map;

    map = malloc(sizeof(char *) * rows);
    for (int mallo = 0; mallo < rows; mallo++)
        map[mallo] = malloc(sizeof(char) * cols);
    map = put_in_map(map);
    return (map);
}