/*
** EPITECH PROJECT, 2019
** get_input.c
** File description:
** gets input from user with errors
*/

#include "../include/my.h"
#include "../include/my_navy.h"

char *get_input(char *buffer)
{
    buffer[0] = 66;
    buffer[1] = 50;
    read(0, buffer, 3);
    buffer[2] = '\0';
    if (buffer[0] < 65 || buffer[0] > 72) {
        write(2, "\nwrong position", 15);
        my_putstr("\nattack: ");
        get_input(buffer);
    } else if (buffer[1] < 49 || buffer[1] > 56) {
        write(2, "\nwrong position", 15);
        my_putstr("\nattack: ");
        get_input(buffer);
    }
    return (buffer);
}

short switch_turns(short turn)
{
    if (turn == 0)
        return (1);
    else if (turn == 1)
        return (0);
}

void display_stuff(maps_t all_maps, short turn)
{
    my_putstr("\nmy positions:\n");
    print_map(all_maps.map);
    my_putstr("\nenemy's positions:\n");
    print_map(all_maps.empty_map);
}

void send_signals(char *buffer, int *move, pid_t pid)
{
    move[0] = buffer[0] - 63;
    if (move[0] != 2)
        move[0] += move[0] - 4 / 2;
    move[1] = buffer[1] - 47;
    for (int i = 0; i < move[0]; i++) {
        kill(pid, SIGUSR1);
        usleep(5000);
    }
    kill(pid, SIGUSR2);
    usleep(5000);
    for (int j = 0; j < move[1]; j++) {
        kill(pid, SIGUSR1);
        usleep(5000);
    }
    kill(pid, SIGUSR2);
    usleep(5000);
}

int exit_condition_2(int numbers, maps_t all_maps, int i, int j)
{
    if (all_maps.map[j][i] >= 48 && all_maps.map[j][i] <= 57)
        numbers++;
    return (numbers);
}