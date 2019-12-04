/*
** EPITECH PROJECT, 2019
** my_navy.h
** File description:
** .h for the navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int SIGNALS;

typedef struct maps maps_t;
struct maps
{
    char **map;
    char **empty_map;
};

char **get_map(void);
char **boats_in_map(int ac, char **map, char **av);
void print_map(char **map);
short connect_players(maps_t all_maps, int ac, char **av);
int exit_condition(maps_t all_maps);
char *get_input(char *buffer);
short switch_turns(short turn);
void display_stuff(maps_t all_maps, short turn);
void send_signals(char *buffer, int *move, pid_t pid);
short player(struct sigaction sa, pid_t pid, maps_t all_maps, short turn);
void attack_hit_or_miss(maps_t all_maps, char *buffer);
void defend_hit_or_miss(int *x_y, maps_t all_maps, pid_t pid);
int winning_condition(maps_t all_maps);
int exit_condition_2(int numbers, maps_t all_maps, int i, int j);