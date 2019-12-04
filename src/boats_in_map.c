/*
** EPITECH PROJECT, 2019
** boats_in_map.c
** File description:
** puts the boats int he map.
*/

#include "../include/my.h"
#include "../include/my_navy.h"

char **print_in_map(char **map, int *coord, short way, short flat)
{
    if (flat == 0 && way == 1) {
        for (int j = coord[1]; j <= coord[3]; j++)
            map[j][coord[0]] = coord[4];
    } else if (flat == 1 && way == 1) {
        for (int i = coord[0]; i <= coord[2]; i += 2)
            map[coord[1]][i] = coord[4];
    } else if (flat == 0 && way == 0) {
        for (int k = coord[3]; k >= coord[1]; k++)
            map[k][coord[0]] = coord[4];
    } else if (flat == 1 && way == 0) {
        for (int p = coord[2]; p <= coord[0]; p += 2)
            map[coord[1]][p] = coord[4];
    }
    return (map);
}

char **get_ways(char **map, int *coord, char *buf)
{
    short flat = 0;
    short way = 0;

    if (coord[1] - coord[3] == 0)
        flat++;
    if (flat == 1 && coord[2] - coord[0] > 0)
        way++;
    if (flat == 0 && coord[3] - coord[1] > 0)
        way++;
    map = print_in_map(map, coord, way, flat);
    return (map);
}

char **get_x_y(char **map, char *buf)
{
    int coord[5];

    coord[0] = buf[2] - 63;
    if (coord[0] != 2)
        coord[0] += coord[0] - 4 / 2;
    coord[1] = buf[3] - 47;
    coord[2] = buf[5] - 63;
    if (coord[2] != 2)
        coord[2] += coord[2] - 4 / 2;
    coord[3] = buf[6] - 47;
    coord[4] = buf[0];
    map = get_ways(map, coord, buf);
    return (map);
}

char **boats_in_map(int ac, char **map, char **av)
{
    int fd = 0;
    char *buf = malloc(sizeof(char) * 8);

    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else if (ac == 3)
        fd = open(av[2], O_RDONLY);
    for (int i = 0; i < 4; i++) {
        read(fd, buf, 8);
        buf[7] = ('\0');
        map = get_x_y(map, buf);
    }
    return (map);
}
