/*
** EPITECH PROJECT, 2019
** hit_or_miss.c
** File description:
** determines if it hits.
*/

#include "../include/my.h"
#include "../include/my_navy.h"

void defend_hit_or_miss(int *x_y, maps_t all_maps, pid_t pid)
{
    char input[3];

    input[0] = all_maps.map[0][x_y[0]];
    input[1] = all_maps.map[x_y[1]][0];
    if (x_y[0])
    input[2] = '\0';
    if (all_maps.map[x_y[1]][x_y[0]] == '.') {
        my_putchar('\n');
        my_putstr(input);
        my_putstr(": missed\n");
        kill(pid, SIGUSR1);
        all_maps.map[x_y[1]][x_y[0]] = 'o';
    } else {
        my_putchar('\n');
        my_putstr(input);
        my_putstr(": hit\n");
        kill(pid, SIGUSR2);
        all_maps.map[x_y[1]][x_y[0]] = 'x';
    }
}

void attack_hit_or_miss(maps_t all_maps, char *buffer)
{
    int *input = malloc(sizeof(int) * 2);

    input[0] = buffer[0] - 63;
    if (input[0] != 2)
        input[0] += input[0] - 4 / 2;
    input[1] = buffer[1] - 47;
    if (SIGNALS == 1) {
        my_putstr(buffer);
        my_putstr(": missed\n");
        all_maps.empty_map[input[1]][input[0]] = 'o';
    } else if (SIGNALS == 0) {
        my_putstr(buffer);
        my_putstr(": hit\n");
        all_maps.empty_map[input[1]][input[0]] = 'x';
    }
    SIGNALS = 0;
}

int exit_condition(maps_t all_maps)
{
    int numbers = 0;

    for (int j = 0; j < 10; j++) {
        for (int i = 1; i < 18; i++) {
            numbers = exit_condition_2(numbers, all_maps, i, j);
        }
    }
    return (numbers);
}

int winning_condition_2(int numbers, maps_t all_maps, int i, int j)
{
    if (all_maps.empty_map[j][i] == 'x')
        numbers++;
    return (numbers);
}

int winning_condition(maps_t all_maps)
{
    int numbers = 0;

    for (int j = 0; j < 10; j++) {
        for (int i = 1; i < 18; i++) {
            numbers = winning_condition_2(numbers, all_maps, i, j);
        }
    }
    return (numbers);
}