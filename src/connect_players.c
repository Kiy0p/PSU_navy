/*
** EPITECH PROJECT, 2019
** game_loop.c
** File description:
** game loop, conneciton with players
*/

#include "../include/my.h"
#include "../include/my_navy.h"

void handler(int sig, siginfo_t *info, void *vide)
{
    SIGNALS = info->si_pid;
    my_putstr("enemy connected\n");
}

short player_one(short win, struct sigaction sa, pid_t pid, maps_t all_maps)
{
    my_putstr("my_pid: ");
    my_putnbr(pid);
    my_putstr("\nwaiting for enemy connection...\n\n");
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    pid = SIGNALS;
    win = player(sa, pid, all_maps, 1);
    return (win);
}

short player_two(short win, struct sigaction sa, pid_t pid_2, maps_t all_maps)
{
    my_putstr("my_pid: ");
    my_putnbr(pid_2);
    kill(pid_2, SIGUSR2);
    my_putstr("\nsuccessfully connected\n");
    win = player(sa, pid_2, all_maps, 0);
    return (win);
}

short connect_players(maps_t all_maps, int ac, char **av)
{
    struct sigaction sa;
    pid_t pid = getpid();
    int pid_2 = my_getnbr(av[1]);
    short win = 0;

    sa.sa_sigaction = &handler;
    sa.sa_flags = SA_SIGINFO;
    if (ac == 2) {
        win = player_one(win, sa, pid, all_maps);
    } else if (ac == 3) {
        win = player_two(win, sa, pid_2, all_maps);
    }
    return (win);
}