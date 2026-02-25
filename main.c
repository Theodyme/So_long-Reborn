#include "lib.h"

void    print_err(char *str, char *call)
{
        printf(RED "[error]: " DEFAULT);
        if (str)
            printf("%s", str);
        if (call)
            printf(BLACK " [%s]\n" DEFAULT, call);
        return ;
}

void    print_success(char *str, char *call)
{
        printf(GREEN "[log]: " DEFAULT);
        if (str)
            printf("%s", str);
        if (call)
            printf(BLACK " [%s]\n" DEFAULT, call);
        return ;
}

void    print_log(char *str, char *call)
{
        printf(BLUE "[log]: " DEFAULT);
        if (str)
            printf("%s", str);
        if (call)
            printf(BLACK " [%s]\n" DEFAULT, call);
        return ;
}


int     main(int ac, char **av)
{
    char        *filename;
    t_map       map_data;
    t_game_data game_data;

    if (ac != 2)
    {
        printf("error: program requires at least and only the map as argument\n");
        return EXIT_FAILURE;
    }

    filename = ft_strdup(av[1]);
    printf(BLUE "[log]: " DEFAULT);
    printf("opening map file [%s] ...\n", filename);

    init_map_data(filename, &map_data);
    init_game_data(&game_data);
    if (open_map(filename, &map_data) == EXIT_FAILURE)
    {
        printf(RED "[log]: " DEFAULT);
        printf("failure opening [%s]. aborting.\n", filename);
    }
    data_builder(&map_data, &game_data);
    flood_fill_call(&map_data, &game_data);

    game_data.map = &map_data;

    launch_game(&game_data);

    free(filename);
    return EXIT_SUCCESS;
}