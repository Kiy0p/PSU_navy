/*
** EPITECH PROJECT, 2019
** player_one.c
** File description:
** file fir the first player
*/

#include "../include/my.h"
#include "../include/my_navy.h"

void counter(int sig, siginfo_t *info, void *vide)
{
    if (sig == 10)
        SIGNALS++;
    if (sig == 12 && SIGNALS != 0)
        SIGNALS += 100;
}

int *get_signals(int *x_y)
{
    SIGNALS = 0;
    while (SIGNALS < 100)
        usleep(5000);
    if (SIGNALS > 100)
        x_y[0] = SIGNALS - 100;
    SIGNALS = 0;
    while (SIGNALS < 100)
        usleep(5000);
    if (SIGNALS > 100) {
        x_y[1] = SIGNALS - 100;
    }
    SIGNALS = 0;
    return (x_y);
}

short game(pid_t pid, maps_t all_maps, short turn)
{
    int move[2];
    char *buffer = malloc(sizeof(char) * 3);
    int *x_y = malloc(sizeof(int) * 2);

    SIGNALS = 0;
    if (turn == 0) {
        my_putstr("\nwaiting for enemy's attack...");
        x_y = get_signals(x_y);
        defend_hit_or_miss(x_y, all_maps, pid);
        usleep(5000);
    } else if (turn == 1) {
        my_putstr("\nattack: ");
        buffer = get_input(buffer);
        send_signals(buffer, move, pid);
        usleep(5000);
        attack_hit_or_miss(all_maps, buffer);
        usleep(5000);
    }
    turn = switch_turns(turn);
    return (turn);
}

short player(struct sigaction sa, pid_t pid, maps_t all_maps, short turn)
{
    int numbers = exit_condition(all_maps);
    int crosses = 0;
    int rounds = 0;

    sa.sa_sigaction = &counter;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    display_stuff(all_maps, turn);
    while (numbers > 0) {
        turn = game(pid, all_maps, turn);
        numbers = exit_condition(all_maps);
        crosses = winning_condition(all_maps);
        if (crosses == 14)
            return (0);
        if ((rounds / 2) * 2 != rounds)
            display_stuff(all_maps, turn);
        rounds++;
    }
    return (1);
}