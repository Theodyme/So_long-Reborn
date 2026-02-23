#include "lib.h"

int    init_map_data(char *filename, t_map **map_data)
{
   *map_data = malloc(sizeof(t_map));
    if (!*map_data)
        return EXIT_FAILURE;
    count_map_height(filename, map_data);
    printf("%d\n", (*map_data)->y);
    (*map_data)->map = malloc(sizeof(char *) * ((*map_data)->y + 1));
    (*map_data)->x = 0;
    printf(BLUE "[log]: " DEFAULT);
    printf("initiated map data.\n");
    return EXIT_SUCCESS;
}

int    init_game_data(t_game_data **game_data)
{
    *game_data = malloc(sizeof(t_game_data));
    if (!*game_data)
        return EXIT_FAILURE;
    (*game_data)->player = 0;
    (*game_data)->items = 0;
    (*game_data)->exit = 0;
    return EXIT_SUCCESS;
}

int    data_builder(t_map **map_data, t_game_data **game_data)
{
    int i;
    int j;

    i = 0;
    while ((*map_data)->map[i]) {
        j = 0;
        while ((*map_data)->map[i][j])
        {
            // print_log(NULL, NULL);
            // printf("loading map[%d][%d] = [%c]\n", i, j, (*map_data)->map[i][j]);
            if ((*map_data)->map[i][j] == 'E')
                (*game_data)->exit += 1;
            if ((*map_data)->map[i][j] == 'P')
            {
                (*game_data)->player += 1;
                (*game_data)->pposx = j;
                (*game_data)->pposy = i;
            }
            if ((*map_data)->map[i][j] == 'C')
                (*game_data)->items += 1;
            j++;
        }
        i++;
    }
    print_log(NULL, NULL);
    printf("found %d exit, %d player, %d item(s).\n", (*game_data)->exit, (*game_data)->player, (*game_data)->items);
    print_log(NULL, NULL);
    printf("player is at position [%d][%d] at the start of the game.\n", (*game_data)->pposy, (*game_data)->pposx);
    if ((*game_data)->exit != 1 || (*game_data)->player != 1 || (*game_data)->items == 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}