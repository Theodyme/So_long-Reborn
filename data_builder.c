#include "lib.h"

int    init_map_data(char *filename, t_map *map_data)
{
    count_map_height(filename, map_data);
    printf("%d\n", map_data->y);
    map_data->map = malloc(sizeof(char *) * (map_data->y + 1));
    map_data->x = 0;
    printf(BLUE "[log]: " DEFAULT);
    printf("initiated map data.\n");
    return EXIT_SUCCESS;
}

int    init_game_data(t_game_data *game_data)
{
    game_data->pposx = 0;
    game_data->pposy = 0;
    game_data->items = 0;
    game_data->exit = 0;
    return EXIT_SUCCESS;
}

int    data_builder(t_map *map_data, t_game_data *game_data)
{
    int i;
    int j;

    i = 0;
    while (map_data->map[i]) {
        j = 0;
        while (map_data->map[i][j])
        {
            if (map_data->map[i][j] == 'E')
                game_data->exit += 1;
            if (map_data->map[i][j] == 'P')
            {
                game_data->pposx = j;
                game_data->pposy = i;
            }
            if (map_data->map[i][j] == 'C')
                game_data->items += 1;
            j++;
        }
        i++;
    }
    print_log(NULL, NULL);
    printf("found %d exit, %d player, %d item(s).\n", game_data->exit, game_data->pposx ? 1 : 0, game_data->items);
    print_log(NULL, NULL);
    printf("player is at position [%d][%d] at the start of the game.\n", game_data->pposy, game_data->pposx);
    if (game_data->exit != 1 || !(game_data->pposx) || game_data->items == 0)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}