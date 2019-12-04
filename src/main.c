/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** first file of the navy
*/

#include "../include/my.h"
#include "../include/my_navy.h"

void display_msg(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] [navy_positions]\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player.");
    my_putstr(" pid of the first player.\n\tnevy_positions:  file ");
    my_putstr("representing the positions of the ships.\n");
}

short error_file(int ac, char **av)
{
    int error = 0;
    int player = 0;

    if (ac == 2)
        error = open(av[1], O_RDONLY);
    else if (ac == 3)
        error = open(av[2], O_RDONLY);
    if (error == -1) {
        write(2, "Error, invalid file\n", 21);
        return (84);
    }
}

int file_errors(int ac, char **av)
{
    int fd = 0;
    int bytes = 0;
    int back_n = 0;
    char *buff = malloc(sizeof(char));

    if (ac == 2)
        fd = open(av[1], O_RDONLY);
    else if (ac == 3)
        fd = open(av[2], O_RDONLY);
    while (read(fd, buff, 1) != 0) {
        bytes++;
        if (buff[0] == '\n')
            back_n++;
        else if (buff[0] > 72)
            return (84);
        else if (buff[0] > 10 && buff[0] < 49)
            return (84);
    }
    if (bytes != 31 || back_n != 3)
        return (84);
}

int more_errors(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        write(2, "You must give 1 or 2 argument(s)\n", 33);
        return (84);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        display_msg();
    } else if (ac == 2 || ac == 3) {
        if (error_file(ac, av) == 84)
            return (84);
        if (file_errors(ac, av) == 84)
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    short win = 0;
    char **map;
    char **empty_map;
    int errors = 0;
    maps_t all_maps;

    errors = more_errors(ac, av);
    if (errors == 84)
        return (84);
    map = get_map();
    empty_map = get_map();
    map = boats_in_map(ac, map, av);
    all_maps.map = map;
    all_maps.empty_map = empty_map;
    win = connect_players(all_maps, ac, av);
    if (win == 0)
        my_putstr("\nI won\n");
    else if (win == 1)
        my_putstr("\nEnemy won\n");
    return (win);
}
